//
//  student.cpp
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//
//  functions from student.h



#include "student.h"
#include <iostream>
using namespace std;

//parameterless
Student::Student(){
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArrSize; ++i) this->daysInCourse[i] = 0;
    this->degreeProg = DegreeProgram::SOFTWARE;
};

//full constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[],DegreeProgram degreeProg){
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArrSize; ++i) this ->daysInCourse[i] = daysInCourse[i];
    this->degreeProg = degreeProg;
}

//destructor
Student::~Student() {}


//getter/accessor functions
    string Student::getStId(){
        return this->studentId;
    }
    string Student::getFName(){
        return this->firstName;
    }
    string Student::getLName(){
        return this->lastName;
    }
    string Student::getEAddress(){
        return this->emailAddress;
    }
    int Student::getAge(){
        return this->age;
    }
    const int* Student::getDaysInCourse(){
        return this->daysInCourse;
    }
    DegreeProgram Student::getDegreeProgram(){
        return this->degreeProg;
    }


//setters/mutator functions
    void Student::setStId(string studentId){
        this->studentId = studentId;
    }
    void Student::setFName(string firstName){
        this->firstName = firstName;
    }
    void Student::setLName(string lastName){
        this->lastName = lastName;
    }
    void Student::setEAddress(string emailAddress){
        this->emailAddress = emailAddress;
    }
    void Student::setAge(int age){
        this->age = age;
    }
    void Student::setDaysInCourse(const int daysInCourse[]){
        for (int i = 0; i < daysInCourseArrSize; ++i) this->daysInCourse[i] = daysInCourse[i];
    }
    void Student::setDegreeProgram(DegreeProgram degreeProg){
        this->degreeProg = degreeProg;
    }


//printing student data
void Student::print(){
    cout << this->studentId << '\t';
    cout << "First Name: " << this->firstName << '\t';
    cout << "Last Name: " << this->lastName << '\t';
    cout << this->age << '\t';
    cout << "daysInCourse: {" << this->daysInCourse[0] << ", ";
    cout << this->daysInCourse[1] << ", ";
    cout << this->daysInCourse[2] << "}" << '\t';
    cout << " Degree Program: " << degreeProgramStrings[(int)this->degreeProg];
    cout << endl;
}

