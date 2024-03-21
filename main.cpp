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

int main(){

system ("pause");
return 0;
}
