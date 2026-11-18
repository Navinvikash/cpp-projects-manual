#include <iostream>
#include <string>
using namespace std;

int main()
{
    string names[4] = {"Arun", "Bala", "Kumar", "Ravi"};
    int marks[4] = {85, 72, 91, 65};
    char grades[4];

    // Sort by marks, highest first (bubble sort)
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3 - i; j++)
            if (marks[j] < marks[j + 1])
            {
                swap(marks[j], marks[j + 1]);
                swap(names[j], names[j + 1]);
            }

    // Grades and total
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        if (marks[i] >= 90) grades[i] = 'A';
        else if (marks[i] >= 75) grades[i] = 'B';
        else if (marks[i] >= 50) grades[i] = 'C';
        else grades[i] = 'F';
        total += marks[i];
    }

    cout << "Student Grade Analyzer" << endl;
    cout << "---------------------" << endl;
    cout << "Name\tMark\tGrade" << endl;
    for (int i = 0; i < 4; i++)
        cout << names[i] << "\t" << marks[i] << "\t" << grades[i] << endl;

    // First student above 80
    for (int i = 0; i < 4; i++)
        if (marks[i] > 80)
        {
            cout << "\nFirst student scoring above 80: " << names[i] << endl;
            break;
        }

    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << (float)total / 4 << endl;
    return 0;
}