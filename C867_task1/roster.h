#pragma once
#include "student.h"
#include <vector>
#include <string>

class Roster {
public:
    //Constructors/Desctructors
    ~Roster();

    //Accessors
    Student* getClassRosterArray(int index);

    //Other Member Functions
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAdress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    //Member Variables
    std::vector<Student*> classRosterArray[5];
};
