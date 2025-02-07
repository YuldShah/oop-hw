#ifndef LMS_H
#define LMS_H

#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
using namespace std;

class LMS {
private:
    string name;
    vector<Student> students;
    vector<Course> courses;

public:
    LMS(const string& name);
    void addStudent(const Student& student);
    void addCourse(const Course& course);
    void addStudentToCourse(int studentId, int courseId);
    void printDetails() const;
};

#endif // LMS_H
