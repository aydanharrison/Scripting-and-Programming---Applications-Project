//
//  roster.cpp
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//
#include <iostream>
#include <vector>
#include "roster.h"
//#include <string.h>
using namespace std;


Student** Roster::getStudentData(){
    return Roster::students;
}



void Roster::parse(string row){
    vector<string> outcome;
    size_t start;
    size_t end = 0;
    while((start = row.find_first_not_of(',', end)) != string::npos){
        end = row.find(',', start);
        outcome.push_back(row.substr(start, end - start));
    }
    DegreeProgram dp = DegreeProgram::SECURITY;//default degree program
    switch (outcome.at(8).back()){
        case 'K': dp = DegreeProgram::NETWORK; break;
        case 'E': dp = DegreeProgram::SOFTWARE; break;
           
    }
    add(outcome.at(0), outcome.at(1), outcome.at(2), outcome.at(3), stoi(outcome.at(4)), stoi(outcome.at(5)), stoi(outcome.at(6)), stoi(outcome.at(7)), dp);
}

//add
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProg){
    
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    students[++lastOnList] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProg);
}

//remove from roster by studentID, error messsage if student ID does not exist
void Roster::remove(string studentId){
    bool idFound = false;
    for (int i = 0; i < Roster::lastOnList; ++i){
        if (students[i]->getStId() == studentId){
            idFound = true;
            Student* temporary = students[i];
            students[i] = students[classRosterArray - 1];
            students[classRosterArray - 1] = temporary;
            Roster::lastOnList--;
        }
    
    }
    if (idFound){
        cout << "Student " << studentId << " removed." << endl;
      
    }
    else {
        cout << "Error: Student " << studentId << " not found." << endl;
    }
   
}


//print all
void Roster::printAll(){
    for (int i = 0; i <= Roster::lastOnList; ++i) Roster::students[i]->print();
}

//average days in course
void Roster::printAverageDaysInCourse(string studentId){
    for (int i = 0; i <= Roster::lastOnList; ++i){
        if (students[i]->getStId() == studentId){
            cout << studentId << ": ";
            cout << (students[i]->getDaysInCourse()[0] + students[i]->getDaysInCourse()[1] + students[i]->getDaysInCourse()[2]) / 3 << endl;
        }
    }
}

//printing invalid emails
// valid email includes "@", and "."
//should NOT have " " (space)
void Roster::printInvalidEmails(){
    for (int i = 0; i <= Roster::lastOnList; ++i){
        string email = Roster::getStudentData()[i]->getEAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
            cout << email << endl;
    }
}

//print student info for degree program specified by enum type
void Roster::printByDegreeProgram(DegreeProgram dp){
    for (int i = 0; i <= Roster::lastOnList; ++i){
        if (Roster::students[i]->getDegreeProgram() == dp) students[i]->print();
    }
}


//destructor
    Roster::~Roster(){
    for (int i = 0; i < classRosterArray; ++i){
        cout << "Destructor for " << students[i]->getStId() << endl;
        delete students[i];
        students[i] = nullptr;
    }
}
