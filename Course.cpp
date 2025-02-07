#include "Course.h"
#include "Student.h"
#include <iostream>
#include <algorithm>
using namespace std;

Course::Course(int id, const string& name, int credits): id(id), name(name), credits(credits){}
int Course::getId() const { return id; }
string Course::getName() const { return name; }
int Course::getCredits() const { return credits; }
bool Course::hasStudent(const Student& student) const {
    for(int studentId: students)
        if(studentId==student.getId()) return true;
    return false;
}
bool Course::addStudent(const Student& student) {
    if(hasStudent(student)) return false;
    students.push_back(student.getId());
    return true;
}
void Course::dropStudent(const Student& student) {
    students.erase(remove(students.begin(), students.end(), student.getId()), students.end());
}
void Course::printDetails() const {
    cout << "Course ID: " << id << ", Name: " << name << ", Credits: " << credits << endl;
    cout << "Enrolled Students: ";
    for(int studentId: students) cout << studentId << " ";
    cout << endl;
}
int Course::getCourseCreditsById(const vector<Course>& courses, int courseId) {
    for(const Course& course: courses) {
        if(course.getId()==courseId) return course.getCredits();
    }
    return 0;
}
