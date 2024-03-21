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

void Student::save() {
    ofstream file("C:\\Users\\HP\\Desktop\\student.txt", ios::app);
    file << studentID << endl;
    file << name << endl;
    file << email << endl;
    for (Course* course : coursesEnrolled) {
        file << course->courseCode << endl;
    }
    file.close();
}
void Teacher::save() {
    ofstream file("C:\\Users\\HP\\Desktop\\Teacher.txt",ios::app);
    file << teacherID << endl;
    file << name << endl;
    file << email << endl;
    for (Course* course : coursesTaught) {
        file << course->courseCode << endl;
    }
    file.close();
}

void Course::save() {
    ofstream file("C:\\Users\\HP\\Desktop\\course.txt", ios::app);
    file << courseCode << endl;
    file << courseName << endl;
    if (teacher != nullptr) {
        file << teacher->teacherID << endl;
    }
    for (Student* student : studentsEnrolled) {
        file << student->studentID << endl;
    }
    file.close();
}

void Student::load() {
    ifstream file("C:\\Users\\HP\\Desktop\\student.txt", ios::app);
    if (file.is_open()) {
        getline(file, studentID);
        getline(file, name);
        getline(file, email);
        string courseCode;
        while (getline(file, courseCode)) {
            Course* course = new Course();
            course->courseCode = courseCode;
            coursesEnrolled.push_back(course);
        }
        file.close();
    }
    else {
        cout << "No saved data found." << endl;
    }
}


void Teacher::load() {
    ifstream file("C:\\Users\\HP\\Desktop\\Teacher.txt", ios::app);
    if (file.is_open()) {
        getline(file, teacherID);
        getline(file, name);
        getline(file, email);
        string courseCode;
        while (getline(file, courseCode)) {
            Course* course = new Course();
            course->courseCode = courseCode;
            coursesTaught.push_back(course);
        }
        file.close();
    }
    else {
        cout << "No saved data found." << endl;
    }
}

void Course::load() {
    ifstream file("C:\\Users\\HP\\Desktop\\Course.txt", ios::app);
    if (file.is_open()) {
        getline(file, courseCode);
        getline(file, courseName);
        string teacherId;
        getline(file, teacherId);
        teacher = new Teacher();
        teacher->teacherID = teacherId;
        string studentId;
        while (getline(file, studentId)) {
            Student* student = new Student();
            student->studentID = studentId;
            studentsEnrolled.push_back(student);
        }
        file.close();
    }
    else {
        cout << "No saved data found." << endl;
    }
}

int main(){

system ("pause");
return 0;
}
