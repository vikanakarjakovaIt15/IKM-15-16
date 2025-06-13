#include "List.h"
#include <cstdlib>
#include <iomanip>
#include <stdexcept>

using namespace std;

Node::Node(Student* s)
        : student(s), next(nullptr), prev(nullptr) {}

StudentList::StudentList()
        : head(nullptr), count(0) {}

StudentList::~StudentList() {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    for (int i = 0; i < count; ++i) {
        Node* temp = current;
        current = current->next;
        delete temp->student; //удаляем объект student
        delete temp; //удаляем узел списка
    }
}

void StudentList::addStudent(const std::string& name) {
    Student* s = new Student(name); //создание студента с именем
    insertBack(s); //добавление в конец списка
}

void StudentList::insertBack(Student* student) {
    Node* newNode = new Node(student);
    if (head == nullptr) { //если список пустой
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    ++count;
}

void StudentList::playGame(int rounds) {
    if (head == nullptr || count == 0) {
        throw runtime_error("Список пуст. Невозможно начать игру.");
    }

    Node* current = head;

    for (int i = 0; i < rounds; ++i) {
        int number = rand() % 21 - 10; //случайные числа от -10 до 10

        cout << "\nРаунд " << i + 1 << ": Выпало число " << number << '\n';

        if (number == 0) {
            cout << "Ничего не происходит. Переход к следующему раунду.\n";
            continue;
        }

        int steps = abs(number);
        for (int i = 0; i < steps; ++i) { //перемещаемся по списку
            current = (number > 0) ? current->next : current->prev;
        }

        current->student->increaseRating();
        //ученик на котором остановились делает доброе дело
        cout << "Доброе дело делает: " << current->student->name << '\n';
        cout << "Рейтинг теперь: " << current->student->rating << '\n';

        current = (number > 0) ? current->next : current->prev;
        //следующий отсчет начнется с ученика рядом с текущим
    }
}

void StudentList::sortByRating() {
    if (head == nullptr || count < 2) {
        return;
    }
    //сортировка не по возрастанию
    for (int i = 0; i < count - 1; ++i) {
        Node* current = head;
        for (int j = 0; j < count - 1; ++j) {
            Node* nextNode = current->next;
            if (current->student->rating < nextNode->student->rating) {
                swap(current->student, nextNode->student);
            }
            current = current->next;
        }
    }
}

void StudentList::printResults() const {
    cout << "\n=== Итоги игры ===\n";
    Node* current = head;
    for (int i = 0; i < count; ++i) {
        cout << setw(15) << current->student->name << " | Рейтинг: "
                  << current->student->rating << '\n';
        current = current->next;
    }
}


