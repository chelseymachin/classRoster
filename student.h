#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student
{
public:
    const static int numberOfDaysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numberOfDays[numberOfDaysArraySize];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], DegreeProgram degreeProgram);
    ~Student();

    /* getters */
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumberOfDays();
    DegreeProgram getDegreeProgram();

    /* setters */
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumberOfDays(int numberOfDays[]);
    void setDegreeProgram(DegreeProgram dp);

    /* print functions */
    static void printHeader();

    void print();
};
