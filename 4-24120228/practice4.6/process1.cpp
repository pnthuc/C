#include "process1.h"
#include <iostream>

void enterStudent(Student &student) {
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);
    std::cout << "Enter student GPA: ";
    std::cin >> student.gpa;
}

void printStudentGPAAndRank( Student student) {
    std::cout << "Student Name: " << student.name << std::endl;
    std::cout << "Student GPA: " << student.gpa << std::endl;

    std::string rank;
    if (student.gpa >= 8.5)
        rank = "Excellent";
    else if (student.gpa >= 7.0)
        rank = "Good";
    else if (student.gpa >= 5.0)
        rank = "Fair";
    else
        rank = "Failed";

    std::cout << "Student Rank: " << rank << std::endl;
}