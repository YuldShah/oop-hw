#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
using namespace std;
class Student; // forward declaration

class Course {
private:
    int id;
    string name;
    int credits;
    vector<int> students;

public:
    Course(int id, const string& name, int credits);
    int getId() const;
    string getName() const;
    int getCredits() const;
    bool hasStudent(const Student& student) const;
    bool addStudent(const Student& student);
    void dropStudent(const Student& student);
    void printDetails() const;

    static int getCourseCreditsById(const vector<Course>& courses, int courseId);
};

#endif // COURSE_H
