#include "roster.h"
using namespace std;

int main() {

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chelsey,Machin,cmachi2@wgu.edu,27,14,25,5,SOFTWARE"
    };

    const int numStudents = 5;

    cout << "This is a final project for C867 using C++ by Student ID #001221846 - Chelsey Machin" << endl;
    cout << endl;

    Roster roster;

    for (int i = 0; i < numStudents; i++)
    {
        roster.parse(studentData[i]);
    }
    cout << "Displaying all students in roster" << endl;
    roster.printAll();
    cout << endl;

    cout << "Displaying invalid email addresses" << endl;
    roster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in course" << endl;
    roster.printAverageDaysInCourse("A1");
    roster.printAverageDaysInCourse("A2");
    roster.printAverageDaysInCourse("A3");
    roster.printAverageDaysInCourse("A4");
    roster.printAverageDaysInCourse("A5");

    cout << "Displaying by degree program: software" << endl;
   roster.printByDegreeProgram(SOFTWARE);


   roster.remove("A3");
   roster.remove("A3");









    return 0;
};