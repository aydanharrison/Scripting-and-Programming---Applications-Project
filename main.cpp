//
//  main.cpp
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//

#include <iostream>
#include "roster.h"
using namespace std;

int main() {
    //1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010049946" << endl;
    cout << "Name : Aydan Harrison" << endl;
    
    
   
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Ering,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Aydan,Harrison,aha1617@wgu.edu,24,21,24,30,SOFTWARE"
    };
    const int numberOfStudents = 5;
    
    
    
    Roster classRoster;
    for (int i = 0; i < numberOfStudents; ++i){
        classRoster.parse(studentData[i]);
    }
    cout << endl;
    
    
    cout << "Display all students:" << endl;
    classRoster.printAll();
    cout << endl;
    
    cout << "Displaying Invalid Emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Display average days in course: " << endl;
    for (int i = 0; i < numberOfStudents; ++i) classRoster.printAverageDaysInCourse(classRoster.getStudentData()[i]->getStId());
    cout << endl;
    
    cout << "Displaying by Degree Program: SOFTWARE: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    
    
    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.remove("A3");
    cout << endl;
    
    
    
    return 0;
}
