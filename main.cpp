#include <iostream>
#include "LMS.h"
using namespace std;

int main() {
    string nameLMS;
    cin >> nameLMS;
    LMS myLMS(nameLMS);

    int number_students;
    cin >> number_students;
    for (int i = 0; i < number_students; ++i) {
        int id;
        string name;
        cin >> id >> name;
        Student s1(id, name);
        myLMS.addStudent(s1);
    }

    int number_courses;
    cin >> number_courses;
    for (int i = 0; i < number_courses; ++i) {
        int id, credits;
        string name;
        cin >> id >> name >> credits;
        Course c1(id, name, credits);
        myLMS.addCourse(c1);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int student_id, course_id;
        cin >> student_id >> course_id;
        myLMS.addStudentToCourse(student_id, course_id);
    }

    myLMS.printDetails();
    return 0;
}
