#include <iostream>
#include <vector>
using namespace std;

// کلاس پایه: شخص
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// کلاس مشتق: دانش‌آموز
class Student : public Person {
private:
    string studentID;
    int grade;
    float average;

public:
    Student(string n, int a, string id, int g, float avg)
        : Person(n, a), studentID(id), grade(g), average(avg) {}

    void displayInfo() override {
        cout << "Student Info:\n";
        Person::displayInfo();
        cout << "ID: " << studentID << "\nGrade: " << grade << "\nAverage: " << average << "\n" << endl;
    }
};

// کلاس مدرسه
class School {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void displayAllStudents() {
        cout << "--- All Students ---\n";
        for ( auto& s : students) {
            s.displayInfo();
        }
    }
};

// برنامه اصلی
int main() {
    School mySchool;

    Student s1("Ali Ahmadi", 16, "ST001", 10, 18.5);
    Student s2("Sara Moradi", 17, "ST002", 11, 19.2);

    mySchool.addStudent(s1);
    mySchool.addStudent(s2);

    mySchool.displayAllStudents();

    return 0;
}
