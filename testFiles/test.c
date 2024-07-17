#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro with variable arguments
#define LOG(format, ...) fprintf(stderr, format, __VA_ARGS__)

// Obscure typedef and struct usage
typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person base;
    char *major;
} Student;

// Function pointers
typedef void (*display_func)(void *);

void displayPerson(void *p) {
    Person *person = (Person *)p;
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void displayStudent(void *s) {
    Student *student = (Student *)s;
    printf("Name: %s, Age: %d, Major: %s\n", student->base.name, student->base.age, student->major);
}

// Generic function to display objects
void display(void *obj, display_func func) {
    func(obj);
}

// Function-like macro with code block
#define CREATE_PERSON(name, age) ({ \
    Person *p = (Person *)malloc(sizeof(Person)); \
    p->name = strdup(name); \
    p->age = age; \
    p; \
})

#define CREATE_STUDENT(name, age, major) ({ \
    Student *s = (Student *)malloc(sizeof(Student)); \
    s->base.name = strdup(name); \
    s->base.age = age; \
    s->major = strdup(major); \
    s; \
})

// Static inline function
static inline void sortStudentsByName(Student **students, size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (strcmp(students[j]->base.name, students[j + 1]->base.name) > 0) {
                Student *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// User-defined literal
#define _len(str) (sizeof(str) - 1)

int main() {
    LOG("Program started\n");

    size_t len = _len("test_string");
    LOG("Length of string: %zu\n", len);

    // Creating objects
    Person *person = CREATE_PERSON("John Doe", 45);
    Student *student1 = CREATE_STUDENT("Alice Smith", 20, "Computer Science");
    Student *student2 = CREATE_STUDENT("Bob Johnson", 22, "Mathematics");

    // Using an array to store objects
    Student *students[] = {student1, student2};
    size_t studentCount = sizeof(students) / sizeof(students[0]);

    // Displaying the objects
    printf("Before sorting:\n");
    for (size_t i = 0; i < studentCount; ++i) {
        display(students[i], (display_func)displayStudent);
    }

    // Sorting the students by name
    sortStudentsByName(students, studentCount);

    printf("After sorting:\n");
    for (size_t i = 0; i < studentCount; ++i) {
        display(students[i], (display_func)displayStudent);
    }

    // Cleaning up
    free(person->name);
    free(person);
    for (size_t i = 0; i < studentCount; ++i) {
        free(students[i]->base.name);
        free(students[i]->major);
        free(students[i]);
    }

    LOG("Program finished\n");
    return 0;
}

