#include "Student.h"
#include "Course.h"
#include <iostream>
#include <algorithm>
using namespace std;

Student::Student(int sid, const string& name) : id(sid), name(name) {}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

vector<int> Student::getEnrolledCourses() const {
    return enrolledCourses;
}

bool Student::takesCourse(const Course& course) const {
    for (int courseId : enrolledCourses) {
        if (courseId == course.getId()) {
            return true;
        }
    }
    return false;
}

bool Student::takeCourse(const Course& course, const vector<Course>& allCourses) {
    if (takesCourse(course)) {
        return false;
    }
    int totalCredits = course.getCredits();
    for (int courseId : enrolledCourses) {
        for (const Course& c : allCourses) {
            if (c.getId() == courseId) {
                totalCredits += c.getCredits();
                break;
            }
        }
    }
    if (totalCredits > MAX_ALLOWED_CREDITS) {
        return false;
    }
    enrolledCourses.push_back(course.getId());
    return true;
}

void Student::dropCourse(const Course& course) {
    enrolledCourses.erase(remove(enrolledCourses.begin(), enrolledCourses.end(), course.getId()), enrolledCourses.end());
}

void Student::printDetails() const {
    cout << "Student ID: " << id << ", Name: " << name << endl;
    cout << "Enrolled Courses: ";
    for (int courseId : enrolledCourses) {
        cout << courseId << " ";
    }
    cout << endl;
}

