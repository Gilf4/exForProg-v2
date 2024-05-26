#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayInfo() = 0;
};

class Student : public Person {
private:
    int studentID;
    vector<string> enrolledCourses;

public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}

    void enrollCourse(string course) {
        enrolledCourses.push_back(course);
    }

    void displayInfo() override {
        cout << "Student Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
        cout << "Enrolled Courses: ";
        for (const string& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    // Добавляем метод для отображения информации о курсах студента
    void displayCourses() {
        cout << "Enrolled Courses for " << name << ": ";
        for (const string& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> teachingCourses;

public:
    Professor(string n, int a, string dept) : Person(n, a), department(dept) {}

    void addCourse(string course) {
        teachingCourses.push_back(course);
    }

    void displayInfo() override {
        cout << "Professor Name: " << name << ", Age: " << age << ", Department: " << department << endl;
        cout << "Teaching Courses: ";
        for (const string& course : teachingCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    // Добавляем метод для отображения информации о курсах, которые преподает профессор
    void displayCourses() {
        cout << "Teaching Courses for " << name << ": ";
        for (const string& course : teachingCourses) {
            cout << course << " ";
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
    
    // Добавляем метод для отображения курсов студентов и преподавателей
    void showAllCourses() {
        for (Person* member : members) {
            if (dynamic_cast<Student*>(member)) {
                Student* student = dynamic_cast<Student*>(member);
                student->displayCourses();
            } else if (dynamic_cast<Professor*>(member)) {
                Professor* professor = dynamic_cast<Professor*>(member);
                professor->displayCourses();
            }
        }
    }
};

int main() {
    University uni;

    Professor* prof1 = new Professor("Dr. Smith", 45, "Computer Science");
    Professor* prof2 = new Professor("Dr. Jones", 50, "Mathematics");

    Student* s1 = new Student("Alice", 20, 1001);
    Student* s2 = new Student("Bob", 22, 1002);

    uni.addMember(prof1);
    uni.addMember(prof2);
    uni.addMember(s1);
    uni.addMember(s2);

    prof1->addCourse("Data Structures");
    prof2->addCourse("Calculus");

    s1->enrollCourse("Data Structures");
    s1->enrollCourse("Calculus");
    s2->enrollCourse("Calculus");

    cout << "University Members:" << endl;
    uni.showAllMembers();

    cout << "\nUniversity Courses:" << endl;
    uni.showAllCourses();

    return 0;
}
