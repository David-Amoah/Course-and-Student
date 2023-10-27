// Copyright 2023
// Author: David Amoah

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

//#include "NameList.h"
//#include "NameNode.h"

#include "Student.h"
#include "Course.h"
#include <iostream>

using std::cout;

#include <cxxtest/TestSuite.h>

class newCxxTest : public CxxTest::TestSuite {
public:


    void testMyStudent() {   ///test for the NameNode class
        Student newStudent1("David", "Amoah", 4.0);
        Student newStudent2("David", "Amoah", 4.0);

        TS_ASSERT_EQUALS(newStudent1.GetFirst(),"David");
        TS_ASSERT_EQUALS(newStudent1.GetLast(),"Amoah");
        TS_ASSERT_DELTA(newStudent1.GetGPA(),4.0,0.001);

        cout << newStudent1;

        if (newStudent1 == newStudent2) {
            cout << "They are the same" << endl;
        }
    }

    void testMyCourse() {
        Student newStudent1("David", "Amoah", 100);
        Course course;
        course.LoadFile("course1.txt");

        cout << course.FindStudentHighestGpa();

        course.AddStudent(newStudent1);

        cout << course.FindStudentHighestGpa();

        course.Print();

        course.RemoveStudent(newStudent1);

        course.GetRoster();

        course.PassCourse("course1.txt");

        try {
            course.PassCourse("course2.txt");
        }
        catch (runtime_error& e) {
            cout << e.what();
        }

        cout << course;





    };







};
#endif /* NEWCXXTEST_H */
