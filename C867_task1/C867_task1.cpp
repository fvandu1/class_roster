#include "roster.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <map>

int main() {
    std::cout << "C867: Scripting and Programming Applications" << std::endl;
    std::cout << "Language: C++" << std::endl;
    std::cout << "Student ID: 010620769" << std::endl;
    std::cout << "Name: Forrest VanDuren " << std::endl;

    const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Forrest,VanDuren,fvandu1@wgu.edu,29,20,25,30,SOFTWARE" };

    Roster classRoster;

    //Variables for parsing student data into Roster::add
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int classTime1;
    int classTime2;
    int ClassTime3;
    DegreeProgram degreeProgram;

    //Parse loop
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); ++i) {
        //Case number that correlates to each parse variable
        int caseNumber = 0;

        //Setting up stream data for parsing
        std::string input = studentData[i];
        std::istringstream stream(input);
        std::string token;

        //Seperates given entry from studentData by commas.
        while (std::getline(stream, token, ',')) {
            switch (caseNumber) {
                //Assign token to its intended variable
                case 0:
                    studentID = token;
                    caseNumber++;
                    break;

                case 1:
                    firstName = token;
                    caseNumber++;
                    break;

                case 2:
                    lastName = token;
                    caseNumber++;
                    break;

                case 3:
                    emailAddress = token;
                    caseNumber++;
                    break;

                case 4:
                    age = stoi(token);
                    caseNumber++;
                    break;

                case 5:
                    classTime1 = stoi(token);
                    caseNumber++;
                    break;

                case 6:
                    classTime2 = stoi(token);
                    caseNumber++;
                    break;

                case 7:
                    ClassTime3 = stoi(token);
                    caseNumber++;
                    break;

                case 8:
                    //Map string to enum for type conversion.
                    std::map<std::string, DegreeProgram> stringToEnum{
                        {"SECURITY", SECURITY},
                        {"NETWORK", NETWORK},
                        {"SOFTWARE", SOFTWARE}
                    };
                    degreeProgram = stringToEnum.find(token)->second;
                    break;

            }
        }
        classRoster.add(studentID, firstName, lastName, emailAddress, age, classTime1, classTime2, ClassTime3, degreeProgram);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray(i)->getStudentID());
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
