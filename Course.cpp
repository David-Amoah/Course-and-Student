// Copyright 2023
// Author: David Amoah

#include <iostream>
#include <fstream>
#include "Course.h"


const vector<Student> &Course::GetRoster() const {
    return roster;
}

Student Course::FindStudentHighestGpa() {
    Student highestGPA = roster.at(0);
    double max = roster.at(0).GetGPA();

    for (size_t i = 0; i < roster.size(); i++) {
        if (roster.at(i).GetGPA() > max) {
            max = roster.at(i).GetGPA();
            highestGPA = roster.at(i);
        }
    }
    return highestGPA;
}

void Course::AddStudent(Student s) {
    roster.push_back(s);
}

void Course::Print() {
    for (size_t i = 0; i < roster.size(); i++) {
        cout << roster.at(i);
    }
}

void Course::PassCourse(string fileName) {
    ofstream outSS;
    outSS.open(fileName);
    while (!outSS.is_open()) {
        throw runtime_error("could not open file");
        return;
    }
    for (size_t i = 0; i < roster.size(); i++) {
        if (roster.at(i).GetGPA() > 74) {
            outSS << roster.at(i) << " " << endl;

        }

    }


    outSS.close();
}

ostream &operator<<(ostream &out, const Course &s) {
    for (size_t i = 0; i < s.roster.size(); i++) {
        out << s.roster.at(i) << endl;
    }
    return out;
}

void Course::LoadFile(string fileName) {
    ifstream inSS;
    inSS.open(fileName);

    cout << "Opening file " << fileName << endl;

    while (!inSS.is_open()) {
        throw runtime_error("Couldn't open");
    }

    string first, last;
    double gpa;

    while (inSS >> first >> last >> gpa) {
        Student newStudent(first,last,gpa);
        roster.push_back(newStudent);
    }

    inSS.close();

}

void Course::RemoveStudent(const Student &student) {
    if (roster.empty()) {
        throw runtime_error("Vector is empty");
    }
    for (size_t i = 0; i < roster.size(); i++) {
        if (roster[i] == student) {
            roster.erase(roster.begin() + i);
            return;
        }

    }
}
