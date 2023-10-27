#include <iostream>
#include "Course.h"
using namespace std;

int main() {
    Course course;
    cout << "Load course:" << endl;
    course.LoadFile("course1.txt");
    course.Print();
    course.PassCourse("passcourse1.txt");
    Course pCourse;
    cout << endl;
    cout << "Pass course:" << endl;
    pCourse.LoadFile("passcourse1.txt");
    //pCourse.Print();
    vector<Student> s = pCourse.GetRoster();
    for (size_t i=0; i<s.size(); i++) {
        cout << s.at(i) << endl;
    }
    cout << endl << "Test remove student Maggie" << endl;
    Student testStudent("Maggie", "Miller",  92);
    course.RemoveStudent(testStudent);
    course.Print();
    return 0;
}
