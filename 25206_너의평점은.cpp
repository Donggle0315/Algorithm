#include <iostream>
#include <string>
#include <vector>

using namespace std;

double getGrade(string grade);

int main() {
    double score[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
    double cgpa = 0;
    double hours = 0;
    
    for (int i = 0; i < 20; i++) {
        string subject;
        double hour;
        string grade;

        cin >> subject >> hour >> grade;
        cgpa += (getGrade(grade) * hour);
        if (grade != "P") hours += hour;
    }

    cout << cgpa / hours << "\n";
}

double getGrade(string grade) {
    double grade_value = 0;    
    switch (grade[0]) {
        case 'A':
            grade_value = 4;
            break;
        case 'B' :
            grade_value = 3;
            break;
        case 'C' :
            grade_value = 2;
            break;
        case 'D' :
            grade_value= 1;
            break;
        default :
            grade_value = 0;
    }

    if (grade[1] == '+') {
        grade_value += 0.5;
    }

    return grade_value;
}