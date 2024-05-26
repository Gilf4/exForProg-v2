#include "iostream"
#include "vector"
#include "string"
#include <complex>
#include <ratio>

using namespace std;

// Базовый класс Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void displayInfo() = 0; // Чисто виртуальная функция для полиморфизма
};

// Класс Student, наследуется от Person
class Student : public Person {
private:
    int studentID;
    vector<string> takenCourses;
    
public:
     Student(string name, int age, int id) : Person(name, age), studentID(id) {}
    
     void addCourse(string course){
         takenCourses.push_back(course);
     }
     
     void displayInfo() {
         cout << "Student Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
         cout << "Taken Courses: ";
         for (int i = 0; i < takenCourses.size(); i++) {
             cout << takenCourses[i] << " ";
         }
         cout << endl;
     }
};

// Класс Professor, наследуется от Person
class Professor : public Person {
private:
    string department;
    vector<string> teachingCourses;

public:
    Professor(string name, int age, string dept) : Person(name, age), department(dept) {}

    void addCourse(string course) {
        teachingCourses.push_back(course);
    }

    void displayInfo() {
        cout << "Professor Name: " << name << ", Age: " << age << ", Department: " << department << endl;
        cout << "Teaching Courses: ";
        for (int i = 0; i < teachingCourses.size(); i++) {
            cout << teachingCourses[i] << " ";
        }
        cout << endl;
    }
};

class University {
private:
    vector<Person*> members;
public:
    ~University() {
        for (Person* member : members) {
            delete member;
        }
    }
    
    void addMember(Person* p) {
        members.push_back(p);
    }
    
    void showAllMembers() {
        for (Person* member : members) {
            member->displayInfo();
        }
    }
    
};

int main(){
    University uni;
    
    Professor* prof1 = new Professor("Dr. Bob", 40, "Computer Science");
    Professor* prof2 = new Professor("Dr. Jones", 55, "Math");
    
    Student* s1 = new Student("Joe", 20, 1001);
    Student* s2 = new Student("Alice", 22, 1002);
    
    uni.addMember(prof1);
    uni.addMember(prof2);
    uni.addMember(s1);
    uni.addMember(s2);

    prof1->addCourse("Data Structures");
    prof2->addCourse("Physics");
    
    s1->addCourse("Data Structures");
    s1->addCourse("Physics");
    s2->addCourse("Physics");

    
    cout << "University Members:" << endl;
    uni.showAllMembers();
    
    return 0;
}
