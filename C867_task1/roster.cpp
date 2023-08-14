#include "roster.h"
#include <iostream>

//Constructors/Destructors
Roster::~Roster() {
    for (int i = 0; i < classRosterArray->size(); i++) {
        delete classRosterArray->at(i);
    }
}

//Accessors
Student* Roster::getClassRosterArray(int index) {
    return classRosterArray->at(index);
}

//Other Member Functions
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAdress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    Student* student = new Student(studentID, firstName, lastName, emailAdress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    classRosterArray->push_back(student);
}

void Roster::remove(std::string studentID) {
    for (int i = 0; i < classRosterArray->size(); ++i) {
        if (classRosterArray->at(i)->getStudentID() == studentID) {
            classRosterArray->erase(classRosterArray->begin() + i);
            break;
        }

        if (i == classRosterArray->size() - 1) {
            std::cout << "Student ID not found" << std::endl;
        }
    }
}

void Roster::printAll() {
    for (int i = 0; i < classRosterArray->size(); ++i) {
        classRosterArray->at(i)->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < classRosterArray->size(); ++i) {
        if (classRosterArray->at(i)->getStudentID() == studentID) {
            int average = (classRosterArray->at(i)->getDaysToComplete(0) + classRosterArray->at(i)->getDaysToComplete(1) + classRosterArray->at(i)->getDaysToComplete(2)) / 3;
            std::cout << "Average number of days for student " << studentID << ": " << average << std::endl;
            break;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < classRosterArray->size(); ++i) {
        if (classRosterArray->at(i)->getEmailAddress().find('@') != std::string::npos && classRosterArray->at(i)->getEmailAddress().find(' ') == std::string::npos) {
            int index = classRosterArray->at(i)->getEmailAddress().find('@');

            if (classRosterArray->at(i)->getEmailAddress().find('.', index) != std::string::npos) {
                continue;
            }
        }

        std::cout << "Email " << classRosterArray->at(i)->getEmailAddress() << " is invalid" << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray->size(); ++i) {
        if (classRosterArray->at(i)->getMajor() == degreeProgram) {
            classRosterArray->at(i)->print();
        }
    }
}