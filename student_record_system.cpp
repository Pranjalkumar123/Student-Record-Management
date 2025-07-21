
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

void addStudent() {
    ofstream fout("students.txt", ios::app);
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    fout << s.roll << " " << s.name << " " << s.marks << endl;
    fout.close();
    cout << "✅ Student added successfully!\n";
}

void displayAll() {
    ifstream fin("students.txt");
    Student s;
    cout << "\n📋 All Student Records:\n";
    while (fin >> s.roll >> s.name >> s.marks) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }
    fin.close();
}

void searchStudent() {
    ifstream fin("students.txt");
    int rollNo;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin >> s.roll >> s.name >> s.marks) {
        if (s.roll == rollNo) {
            cout << "\n🎯 Student Found:\n";
            cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "❌ Student not found!\n";
    fin.close();
}

void deleteStudent() {
    ifstream fin("students.txt");
    ofstream fout("temp.txt");
    int rollNo;
    cout << "Enter Roll Number to Delete: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin >> s.roll >> s.name >> s.marks) {
        if (s.roll == rollNo) {
            found = true;
            continue;
        }
        fout << s.roll << " " << s.name << " " << s.marks << endl;
    }
    fin.close();
    fout.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "🗑️ Student deleted successfully.\n";
    else
        cout << "❌ Student not found.\n";
}

void updateStudent() {
    ifstream fin("students.txt");
    ofstream fout("temp.txt");
    int rollNo;
    cout << "Enter Roll Number to Update: ";
    cin >> rollNo;
    Student s;
    bool found = false;
    while (fin >> s.roll >> s.name >> s.marks) {
        if (s.roll == rollNo) {
            found = true;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter New Marks: ";
            cin >> s.marks;
        }
        fout << s.roll << " " << s.name << " " << s.marks << endl;
    }
    fin.close();
    fout.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "✏️ Student updated successfully.\n";
    else
        cout << "❌ Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Record Management =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
