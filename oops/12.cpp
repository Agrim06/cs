#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    void readPerson() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
public:
    int empId;
    float salary;

    void readEmployee() {
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayEmployee() {
        cout << "Employee ID: " << empId << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    string department;
    string designation;

    void readManager() {
        cin.ignore();
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter designation: ";
        getline(cin, designation);
    }

    void displayManager() {
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
    }
};

int main() {
    Manager m;

    m.readPerson();
    m.readEmployee();
    m.readManager();

    cout << "\n--- Manager Details ---\n";
    m.displayPerson();
    m.displayEmployee();
    m.displayManager();

    return 0;
}
