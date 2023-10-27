// Copyright 2023
// Author: David Amoah

#include <iostream>
#include <string>
#include "Student.h"

using std::string;


Student::Student(string first, string last, double gpa) {
    this -> first = first;
    this -> last = last;
    this -> gpa = gpa;

}

double Student::GetGPA() const {
    return this -> gpa;
}

string Student::GetLast() const {
    return this -> last;
}

string Student::GetFirst() const {
    return this -> first;
}

ostream &operator<<(ostream &out, const Student &s) {
    out << s.first << " " << s.last << " " << s.gpa << endl;
    return out;
}

bool Student::operator==(Student s1) {
    return first == s1.first  && last == s1.last && gpa == s1.gpa;
}
