#include "LMS.h"
#include <iostream>
using namespace std;

LMS::LMS(const string& name): name(name){}

void LMS::addStudent(const Student& student) { students.push_back(student); }

void LMS::addCourse(const Course& course) { courses.push_back(course); }

void LMS::addStudentToCourse(int studentId, int courseId) {
    Student* studentPtr = nullptr;
    Course* coursePtr = nullptr;

    for(auto& student: students){
        if(student.getId()==studentId){ studentPtr=&student; break; }
    }

    for(auto& course: courses){
        if(course.getId()==courseId){ coursePtr=&course; break; }
    }

    if(studentPtr && coursePtr){
        if(studentPtr->takeCourse(*coursePtr, courses)) coursePtr->addStudent(*studentPtr);
    }
}

void LMS::printDetails() const {
    cout << "LMS Name: " << name << endl;
    cout << "Students:" << endl;
    for(const Student& student: students) student.printDetails();
    cout << "Courses:" << endl;
    for(const Course& course: courses) course.printDetails();
}
