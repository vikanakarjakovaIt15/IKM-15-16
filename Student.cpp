#include "Student.h"

using namespace std;

Student::Student(const string& studentName)
        : name(studentName), rating(0) {}

void Student::increaseRating() {
    ++rating; //+1 к рейтингу
}

