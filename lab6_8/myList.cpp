#include "myList.h"

Student::Student(const std::string& s) : surname(s), next(nullptr) {}

Group::Group(int num) : number(num), students(nullptr), next(nullptr) {}

void Group::addStudent(const std::string& surname) {
    Student* newStudent = new Student(surname);
    if (!students) {
        students = newStudent;
    } else {
        Student* temp = students;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void Group::printStudents() {
    std::cout << "Группа " << number << ":\n";
    Student* temp = students;
    while (temp) {
        std::cout << "  " << temp->surname << "\n";
        temp = temp->next;
    }
}

List::List() : head(nullptr) {}

void List::addStudent(int groupNumber, const std::string& surname) {
    push(groupNumber, surname);
}

void List::push(int groupNumber, const std::string& surname) {
    if (!head) {
        head = new Group(groupNumber);
        head->addStudent(surname);
        return;
    }
    
    Group* temp = head;
    while (temp) {
        // Если группа уже есть, добавляем студента
        if (temp->number == groupNumber) {
            temp->addStudent(surname);
            return;
        }
        // Если следующей группы нет, создаём новую
        if (!temp->next) {
            temp->next = new Group(groupNumber);
            temp->next->addStudent(surname);
            return;
        }
        temp = temp->next;
    }
}

void List::pop() {
    if (!head) return;
    
    Group* temp = head;
    head = head->next;
    
    Student* studentTemp = temp->students;
    while (studentTemp) {
        Student* toDelete = studentTemp;
        studentTemp = studentTemp->next;
        delete toDelete;
    }
    delete temp;
}

Group* List::get_head() const {
    return head;
}

void List::clear() {
    while (head) {
        pop();
    }
}

void List::print() {
    if (head == nullptr) {
        cout << "Список групп пуст\n";
    }
    else {
        Group* temp = head;
        while (temp) {
            temp->printStudents();
            temp = temp->next;
        }
    }
}

List::~List() {
    clear();
}