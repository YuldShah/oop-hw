#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Course; // Forward declaration

class Student {
private:
    int id;
    string name;
    vector<int> enrolledCourses;
    static const int MAX_ALLOWED_CREDITS = 18;

public:
    Student(int sid, const string& name);
    int getId() const;
    string getName() const;
    vector<int> getEnrolledCourses() const;
    bool takesCourse(const Course& course) const;
    bool takeCourse(const Course& course, const vector<Course>& allCourses);
    void dropCourse(const Course& course);
    void printDetails() const;
};

#endif // STUDENT_H
