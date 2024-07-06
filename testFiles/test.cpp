#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Base class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    virtual void display() const {
        std::cout << "Name: " << name << ",\n Age: " << age << std::endl;
    }

    std::string getName() const {
        return name;
    }

    virtual ~Person() = default;
};

// Derived class
class Student : public Person {
private:
    std::string major;

public:
    Student(const std::string& name, int age, const std::string& major)
        : Person(name, age), major(major) {}

    void display() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Major: " << major << std::endl;
    }
};

// Template function
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& item : vec) {
        item.display();
    }
}

// Function to use standard library algorithms
void sortStudentsByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });
}

int main() {
    // Creating objects
    Person person("John Doe", 45);
    Student student1("Alice Smith", 20, "Computer Science");
    Student student2("Bob Johnson", 22, "Mathematics");

    // Using a vector to store objects
    std::vector<Student> students = {student1, student2};

    // Displaying the objects
    std::cout << "Before sorting:" << std::endl;
    printVector(students);

    // Sorting the students by name
    sortStudentsByName(students);

    std::cout << "After sorting:" << std::endl;
    printVector(students);

    return 0;
}


