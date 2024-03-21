#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

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

int main(){

system ("pause");
return 0;
}
