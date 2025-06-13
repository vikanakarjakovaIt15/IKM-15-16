#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "List.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); //инициализация генератора случайных чисел

    StudentList list;
    ifstream input("students.txt");
    if (!input.is_open()) {
        cerr << "Не удалось открыть файл students.txt" << endl;
        return 1;
    }

    string name;
    while (getline(input, name)) {
        list.addStudent(name); //считывание имен из файла и добавление в список
    }
    input.close();

    int rounds;
    cout << "Введите количество раундов: ";
    while (!(cin >> rounds) || rounds <= 0) {
        cout << "Некорректный ввод. Повторите: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    list.playGame(rounds); //запуск
    list.sortByRating(); //сортировка
    list.printResults(); //вывод

    return 0;
}
