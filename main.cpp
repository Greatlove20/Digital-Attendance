#include <iostream>
#include <iostream>
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

int main(){
    cout << "Digital Attendance System\n";
    return 0;
}