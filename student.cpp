#include "student.h"

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < numberOfDaysArraySize; i++) this->numberOfDays[i] = 0;
    this->degreeProgram = DegreeProgram::UNKNOWN;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < numberOfDaysArraySize; i++) this->numberOfDays[i] = numberOfDays[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() 
{ 
    return this->studentID; 
}
string Student::getFirstName() 
{ 
    return this->firstName; 
}
string Student::getLastName() 
{ 
    return this->lastName; 
}
string Student::getEmailAddress() 
{ 
    return this->emailAddress; 
}
int Student::getAge() 
{ 
    return this->age; 
}
int* Student::getNumberOfDays() 
{ 
    return this->numberOfDays; 
}
DegreeProgram Student::getDegreeProgram() 
{ 
    return this->degreeProgram; 
}

void Student::setStudentID(string studentID) 
{ 
    this->studentID = studentID; 
}
void Student::setFirstName(string firstName) 
{ 
    this->firstName = firstName; 
}
void Student::setLastName(string lastName) 
{ 
    this->lastName = lastName; 
}
void Student::setEmailAddress(string setEmailAddress) 
{ 
    this->emailAddress = emailAddress; 
}
void Student::setNumberOfDays(int numberOfDays[])
{
    for (int i = 0; i < numberOfDaysArraySize; i++) this->numberOfDays[i] = numberOfDays[i];
}
void Student::setDegreeProgram(DegreeProgram dp) 
{ 
    this->degreeProgram = dp; 
}

void Student::printHeader()
{
    cout << "Student ID|First Name|Last Name|Email Address|Age|Number Of Days|Degree Program" << endl;

}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getNumberOfDays()[0] << '\t';
    cout << this->getNumberOfDays()[1] << '\t';
    cout << this->getNumberOfDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << endl;
}