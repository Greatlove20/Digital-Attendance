#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string indexNumber;
    string name;
    string program;

    void display() {
        cout << indexNumber << " " << name << " " << program << endl;
    }
};
void addStudent() {
    ofstream file("students.txt", ios::app);
    Student s;

    cout << "Index Number: ";
    cin >> s.indexNumber;
    cin.ignore();
    cout << "Name: ";
    getline(cin, s.name);
    cout << "Program: ";
    getline(cin, s.program);

    file << s.indexNumber << "," << s.name << "," << s.program << endl;
    file.close();
}

void viewStudents() {
    ifstream file("students.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
class AttendanceSession {
public:
    string courseCode;
    string date;
    string startTime;
    int duration;
};
AttendanceSession createSession() {
    AttendanceSession s;
    cout << "Course Code: ";
    cin >> s.courseCode;
    cout << "Date (DD_MM_YYYY): ";
    cin >> s.date;
    cout << "Start Time: ";
    cin >> s.startTime;
    cout << "Duration (hours): ";
    cin >> s.duration;
    return s;
}
void markAttendance(AttendanceSession s) {
    ifstream students("students.txt");
    ofstream sessionFile("session_" + s.courseCode + "_" + s.date + ".txt");

    string line;
    char status;

    while (getline(students, line)) {
        cout << "Student: " << line << " (P/A/L): ";
        cin >> status;
        sessionFile << line << "," << status << endl;
    }

    students.close();
    sessionFile.close();
}
int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Create Session\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) createSession();

    } while (choice != 4);

    return 0;
}
