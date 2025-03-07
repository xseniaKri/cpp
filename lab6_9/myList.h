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
    std::string number;
    Student* students;
    Group* next;
    Group(const std::string& num);
    void addStudent(const std::string& surname);
    void printStudents();
};

class List {
private:
    Group* head;
public:
    List();
    void addStudent(const std::string& groupNumber, const std::string& surname);
    void print();
    void clear();
    void push(const std::string& groupNumber, const std::string& surname);
    void pop();
    Group* get_head() const;
    ~List();
};

