#pragma once

#include "Student.h"
#include <iostream>

using namespace std;

struct Node {
    Student* student; //указатель на Student
    Node* next; //следующий узел в списке
    Node* prev; //предыдущий узел в списке

    Node(Student* s);
};

class StudentList {
public:
    StudentList();
    ~StudentList();

    void addStudent(const string& name); //добавить ученика
    void playGame(int rounds); //запуск игры
    void sortByRating(); //сортировка рейтинга
    void printResults() const; //вывод итогов игры

private:
    Node* head;
    int count; //количество учеников в списке

    void insertBack(Student* student);

};

