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
void displayAttendance(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void attendanceSummary(string filename) {
    ifstream file(filename);
    string line;
    int p = 0, a = 0, l = 0;

    while (getline(file, line)) {
        char status = line.back();
        if (status == 'P') p++;
        else if (status == 'A') a++;
        else if (status == 'L') l++;
    }

    cout << "Present: " << p << endl;
    cout << "Absent: " << a << endl;
    cout << "Late: " << l << endl;

    file.close();
}
int main() {
    int choice;
    AttendanceSession session;
    string filename;

    do {
        cout << "\n--- DIGITAL ATTENDANCE SYSTEM ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Attendance Session & Mark Attendance\n";
        cout << "4. View Attendance Summary\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                session = createSession();
                markAttendance(session);
                break;

            case 4:
                cout << "Enter session filename: ";
                cin >> filename;
                attendanceSummary(filename);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
