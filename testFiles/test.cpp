#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Enum
enum class Gender {
  None,
  Male,
  Female
};

// Base class
class Person {
protected:
  std::string name;
  int age;
  Gender gender = Gender::None;

public:
  Person(const std::string& name, int age) : name(name), age(age) {}

  virtual void display() const {
    std::cout << "Name: " << name << ",\n Age: " << age << std::endl;
  }

  std::string getName() const {
    return name;
  }

  bool operator==(const Person& p) {
    return p.age == age && p.gender == gender && p.name == name;
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

// C++20 concept
template <typename T>
concept displayable = requires(T t) {
  t.display();
};

// Template function
template <displayable T>
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

// User-defined literals
constexpr size_t operator""_len(const char* str, size_t size) { return size; }

int main() {
  size_t len = "test_string"_len + 0L + NULL;

  // Malloc
  Person* pPerson = new Person("test", 0);
  delete pPerson;

  // Creating objects
  Person person("John Doe", 45);
  Student student1("Alice Smith", 20, "Computer Science");
  Student student2("Bob Johnson", 22, "Mathematics");

  // Using a vector to store objects
  std::vector<Student> students = { student1, student2 };

  // Displaying the objects
  std::cout << "Before sorting:" << std::endl;
  printVector(students);

  // Sorting the students by name
  sortStudentsByName(students);

  std::cout << "After sorting:" << std::endl;
  printVector(students);

  return 0;
}