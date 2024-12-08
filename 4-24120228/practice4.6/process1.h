#pragma once

#include <string>

struct Student {
    std::string name;
    float gpa;
};

void enterStudent(Student &student);
void printStudentGPAAndRank( Student student);

