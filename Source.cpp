#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Student {
public:
    string name;
    string timetable;
    bool fees_paid;
    string teachers[5];
    int marks;
    Student()
    {}
    Student(string name) {
        this->name = name;
        this->timetable = "English Maths Physics Chemistry Biology";
        this->fees_paid = false;
        this->marks = 0;
    }
};

int main() {
    int num_of_students;
    string name, subject;
    bool fees;
    Student* students;
    int marks;
    string teachers[5] = { "teacher1", "teacher2", "teacher3", "teacher4", "teacher5" };

    cout << "Enter the number of students: ";
    cin >> num_of_students;
    students = new Student[num_of_students];

    for (int i = 0; i < num_of_students; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name;
        students[i] = Student(name);

        cout << "Has the student " << name << " paid the fees (1 for yes, 0 for no)? ";
        cin >> fees;
        students[i].fees_paid = fees;

        cout << "Enter the marks of student " << name << ": ";
        cin >> marks;
        students[i].marks = marks;

        for (int j = 0; j < 5; j++) {
            students[i].teachers[j] = teachers[j];
        }
    }

    ofstream file("Student_Details.txt");
    if (file.is_open()) {
        file << "Student Management System" << endl;
        file << "Number of students: " << num_of_students << endl;

        for (int i = 0; i < num_of_students; i++) {
            file << "Name of student " << i + 1 << ": " << students[i].name << endl;
            file << "Timetable: " << students[i].timetable << endl;
            file << "Fees Paid: " << students[i].fees_paid << endl;
            file << "Marks: " << students[i].marks << endl;
            file << "Teachers: ";
            for (int j = 0; j < 5; j++) {
                file << students[i].teachers[j] << " ";
            }
            file << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open the file" << endl;
    }

    delete[] students;
    return 0;
}
