#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Structure to store student data
struct Student {
    int id;
    string name;
    int age;
    string grade;
};
// Vector to store multiple students
vector<Student> students;
// Function to add a new student
void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore(); // to ignore leftover newline
    cout << "Enter Student Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Grade: ";
    getline(cin, s.grade);
    students.push_back(s);
    cout << "Student added successfully!\n\n";
}
// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n\n";
        return;
    }
    
    cout << "Student List:\n";
    cout << "ID\tName\t\tAge\tGrade\n";
    cout << "---------------------------------\n";
    for (const auto &s : students) {
        cout << s.id << "\t" << s.name << "\t\t" << s.age << "\t" << s.grade << "\n";
    }
    cout << "\n";
}
// Function to search student by ID
void searchStudent() {
    if (students.empty()) {
        cout << "No students found.\n\n";
        return;
    }
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    bool found = false;
    for (const auto &s : students) {
        if (s.id == searchId) {
            cout << "Student Found!\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Age: " << s.age << "\n";
            cout << "Grade: " << s.grade << "\n\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << searchId << " not found.\n\n";
    }
}
int main() {
    int choice;
    do {
        cout << "=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n\n";
        }
    } while (choice != 4);
    return 0;
}
