#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Student {
    std::string surname;
    Student* next;
    Student(const std::string& s);
};

struct Group {
    int number;
    Student* students;
    Group* next;
    Group(int num);
    void addStudent(const std::string& surname);
    void printStudents();
};

class List {
private:
    Group* head;
public:
    List();
    void addStudent(int groupNumber, const std::string& surname);
    void print();
    void clear();
    void push(int groupNumber, const std::string& surname);
    void pop();
    Group* get_head() const;
    ~List();
};

