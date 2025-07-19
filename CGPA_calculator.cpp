#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string grade;
    float creditHours;
    float gradePoints;
};

int main() {
    cout << "Welcome to the CGPA Calculator!" << endl;
    cout << "--------------------------------" << endl;

   
    map<string, float> gradePoints = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    int numSemesters = 0;
    while (true) {
        cout << "Enter the number of semesters: ";
        cin >> numSemesters;
        if (cin.fail() || numSemesters <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number." << endl;
        } else {
            break;
        }
    }

    float overallCredits = 0.0;
    float overallGradePoints = 0.0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        cout << "\n=== Semester " << sem << " ===" << endl;

        int numCourses = 0;
        while (true) {
            cout << "Enter number of courses in semester " << sem << ": ";
            cin >> numCourses;
            if (cin.fail() || numCourses <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number." << endl;
            } else {
                break;
            }
        }

        float semTotalCredits = 0.0;
        float semTotalGradePoints = 0.0;
        vector<Course> courses;

        for (int i = 0; i < numCourses; i++) {
            Course course;
            cout << "\nCourse " << i + 1 << ":" << endl;

            while (true) {
                cout << "Enter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
                cin >> course.grade;
                transform(course.grade.begin(), course.grade.end(), course.grade.begin(), ::toupper);

                if (gradePoints.find(course.grade) != gradePoints.end()) {
                    break;
                } else {
                    cout << "Invalid grade. Please enter a valid grade." << endl;
                }
            }

            while (true) {
                cout << "Enter credit hours: ";
                cin >> course.creditHours;

                if (cin.fail() || course.creditHours <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Credit hours must be a positive number." << endl;
                } else {
                    break;
                }
            }

            course.gradePoints = gradePoints[course.grade] * course.creditHours;
            semTotalCredits += course.creditHours;
            semTotalGradePoints += course.gradePoints;
            courses.push_back(course);
        }

        float semesterGPA = (semTotalCredits > 0) ? (semTotalGradePoints / semTotalCredits) : 0.0;

         
        cout << "\nSemester " << sem << " Results:" << endl;
        cout << "------------------------------------------" << endl;
        cout << left << setw(10) << "Course" << setw(10) << "Grade" << setw(15) << "Credit Hours" << setw(15) << "Grade Points" << endl;
        for (int i = 0; i < courses.size(); i++) {
            cout << left << setw(10) << i + 1
                 << setw(10) << courses[i].grade
                 << setw(15) << courses[i].creditHours
                 << setw(15) << courses[i].gradePoints << endl;
        }

        cout << fixed << setprecision(2);
        cout << "\nSemester GPA: " << semesterGPA << endl;

        
        overallCredits += semTotalCredits;
        overallGradePoints += semTotalGradePoints;
    }

    float cgpa = (overallCredits > 0) ? (overallGradePoints / overallCredits) : 0.0;

    
    cout << "\n====================================" << endl;
    cout << "Total Credit Hours (All Semesters): " << overallCredits << endl;
    cout << "Total Grade Points (All Semesters): " << overallGradePoints << endl;
    cout << "Your CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
