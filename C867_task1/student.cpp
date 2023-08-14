#pragma once
#include "student.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

//Constructors/Destructors
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram major) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToComplete[0] = days1;
    this->daysToComplete[1] = days2;
    this->daysToComplete[2] = days3;
    this->major = major;
}

//Accessors
std::string Student::getStudentID() {
    return studentID;
}

std::string Student::getFirstName() {
    return firstName;
}

std::string Student::getLastName() {
    return lastName;
}

std::string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int Student::getDaysToComplete(int index) {
    //Check for out of range index
    try {

        if (index >= sizeof(daysToComplete)/sizeof(daysToComplete[0])) {
            throw std::runtime_error("Argument must be less than" + sizeof(daysToComplete)/sizeof(daysToComplete[0]));
        }
    }
    catch (std::runtime_error& excpt) {
        std::cout << excpt.what() << std::endl;
        return -1;
    }

    return daysToComplete[index];
}

DegreeProgram Student::getMajor() {
    return major;
}

//Mutators
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToComplete(int index, int daysNumber) {
    daysToComplete[index] = daysNumber;
}

void Student::setMajor(DegreeProgram major) {
    this->major = major;
}

//Other Member Functions
void Student::print() {
    //Temporary array for converting integers from enum to strings.
    std::string enumArray[] = { "Security", "Network", "Software" };

    //Print Statements
    std::cout << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "} ";
    std::cout << "Degree Program: " << enumArray[major] << std::endl;
}



