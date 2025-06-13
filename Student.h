#pragma once

#include <string>

using namespace std;

class Student {
public:
    string name; //имя ученика
    int rating; //рейтинг ученика

    Student(const string& studentName);
    void increaseRating(); //метод для увеличения рейтинга
};
