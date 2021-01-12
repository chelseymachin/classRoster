#include "roster.h"

void Roster::parse(string studentData)
{
	DegreeProgram dp = UNKNOWN;
	if (studentData.back() == 'Y') dp = SECURITY;
	else if (studentData.back() == 'K') dp = NETWORK;
	else if (studentData.back() == 'E') dp = SOFTWARE;

	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string eAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string age = studentData.substr(lhs, rhs - lhs);
	int a = stoi(age);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string numDaysOne = studentData.substr(lhs, rhs - lhs);
	int numDays1 = stoi(numDaysOne);
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string numDaysTwo = studentData.substr(lhs, rhs - lhs);
	int numDays2 = stoi(numDaysTwo);
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string numDaysThree = studentData.substr(lhs, rhs - lhs);
	int numDays3 = stoi(numDaysThree);

	add(sID, fName, lName, eAddress, a, numDays1, numDays2, numDays3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays1, int numberOfDays2, int numberOfDays3, DegreeProgram dp)
{
	int darr[3] = { numberOfDays1,numberOfDays2,numberOfDays3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, dp);
}

void Roster::printAll()
{
	Student::printHeader();
 
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
        this->classRosterArray[i]->print();

	}
} 

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
    }
    cout << endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string eAddress = (classRosterArray[i]->getEmailAddress());
        if (eAddress.find(' ') != string::npos || eAddress.find('.') == string::npos || eAddress.find('@') == string::npos)
        {
            any = true;
            cout << eAddress << ": " << classRosterArray[i]->getStudentID() << endl;
        }
    }
    if (!any) cout << "NONE" << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (studentID == classRosterArray[i]->getStudentID()) {
            cout << (classRosterArray[i]->getNumberOfDays()[0]
                + classRosterArray[i]->getNumberOfDays()[1]
                + classRosterArray[i]->getNumberOfDays()[2]) / 3 << " is the average number of days left for " << studentID << endl;
        }
    }
    cout << endl;
}

void Roster::remove(string studentID)
{
    bool isThere = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            isThere = true;
            if (i < numStudents - 1)
            {
                Student* temporaryHolder = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temporaryHolder;
            }
            Roster::lastIndex--;
        }
    }
    if (isThere)
    {
        cout << studentID << " removed from roster." << endl << endl;
        this->printAll();
    }
    else cout << studentID << " not found." << endl << endl;
}

Roster::~Roster()
{
    cout << "Destructor initiated." << endl << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Erasing student #" << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
