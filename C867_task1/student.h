#pragma once
#include <string>
#include <vector>
#include "degree.h"

class Student {
public:
    //Constructors/Destructors
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram major);

    //Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int getDaysToComplete(int index);
    DegreeProgram getMajor();

    //Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
    void setDaysToComplete(int index, int daysNumber);
    void setMajor(DegreeProgram major);

    //Other Member Functions
    void print();

private:
    //Member Variables
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram major;
};
