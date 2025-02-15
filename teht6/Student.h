#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}

    void setAge(int a) {
        age = a;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void printStudentInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};