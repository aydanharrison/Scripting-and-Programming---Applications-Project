//
//  roster.h
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//
#pragma once
#include <iostream>
#include "student.h"
using namespace std;
/* roster_h */



class Roster {
private:
    int lastOnList = -1; //starting position
    const static int classRosterArray = 5; //size of array of students
    Student* students[classRosterArray] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:
    //parameterless constructor not needed
    //Roster();
    
    //parse
    Student** getStudentData();
    
    void parse(string row);
    
    //all functions in E3
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram dp);
    
    //Destructor
    ~Roster();

};
