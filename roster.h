#pragma once
#include "student.h"
using namespace std;

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];

public:
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays1, int numberOfDays2, int numberOfDays3, DegreeProgram dp);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};
