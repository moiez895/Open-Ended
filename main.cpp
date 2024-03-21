#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Course;
class Student {
public:
    string studentID;
    string name;
    string email;
    vector<Course*> coursesEnrolled;

    void enrollCourse(Course* course);
    void dropCourse(Course* course);
    void viewCourses();
    void save();
    void load();
};

class Teacher {
public:
    string teacherID;
    string name;
    string email;
    vector<Course*> coursesTaught;

    void assignCourse(Course* course);
    void removeCourse(Course* course);
    void viewCourses();
    void save();
    void load();
};

class Course {
public:
    string courseCode;
    string courseName;
    Teacher* teacher;
    vector<Student*> studentsEnrolled;
    int maxCapacity = 30;

    void addStudent(Student* student);
    void removeStudent(Student* student);
    void viewStudents();
    void save();
    void load();
};

void Student::enrollCourse(Course* course) {
    if (course->studentsEnrolled.size() < course->maxCapacity) {
        coursesEnrolled.push_back(course);
        course->addStudent(this);
    }
    else {
        cout << "Course is full." << endl;
    }
}

void Student::dropCourse(Course* course) {
    for (int i = 0; i < coursesEnrolled.size(); i++) {
        if (coursesEnrolled[i] == course) {
            coursesEnrolled.erase(coursesEnrolled.begin() + i);
            course->removeStudent(this);
            break;
        }
    }
}

void Student::viewCourses() {
    for (Course* course : coursesEnrolled) {
        cout << course->courseName << endl;
    }
}

int main(){

system ("pause");
return 0;
}
