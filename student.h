//
//  student.h
//  Scripting and Programming - Applications C++ Project
//
//  Created by Aydan Harrison on 8/21/22.
//

/*D.  For the Student class, do the following:
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•   last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/





#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;
/* student_h */


class Student {
    public:
        const static int daysInCourseArrSize = 3;
    
    private:
        //create student class with all the variables
        string studentId, firstName, lastName, emailAddress;
        int age;
        int daysInCourse[daysInCourseArrSize];
        DegreeProgram degreeProg;
    
    public:
    
    
    //parameterless
    Student();
    
    //full constructor
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProg);
    
    //destructor
    ~Student();
    
    //getters (accessors)
        string getStId();
        string getFName();
        string getLName();
        string getEAddress();
        int getAge();
        const int* getDaysInCourse();
        DegreeProgram getDegreeProgram();
    
    //setters (mutators)
        void setStId(string studentId);
        void setFName(string firstName);
        void setLName(string lastName);
        void setEAddress(string emailAddress);
        void setAge(int age);
        void setDaysInCourse(const int daysInCourse[]);
        void setDegreeProgram(DegreeProgram degreeProg);
    
    
        void print();
                            
    
};
