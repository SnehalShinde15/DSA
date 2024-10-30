/*Assignment No.1a

Name-Snehal Uday Shinde.
PRN-123B1B264.
Assignment Title: Consider a student database of SY COMP class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA. a. Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort b. Arrange list of students alphabetically using shell sort c. Arrange list of students to find out first ten toppers from a class using Radix sort.

a. Insertion Sort to Sort by Roll Number (Ascending Order)*/

#include <iostream>
using namespace std;

// Insertion sort to sort by Roll Number
void insertionSort(int rollNo[], string name[], float sgpa[], int n) {
    for (int i = 1; i < n; i++) {
        int keyRoll = rollNo[i];
        string keyName = name[i];
        float keySgpa = sgpa[i];
        int j = i - 1;

        // Move elements greater than keyRoll one position ahead
        while (j >= 0 && rollNo[j] > keyRoll) {
            rollNo[j + 1] = rollNo[j];
            name[j + 1] = name[j];
            sgpa[j + 1] = sgpa[j];
            j = j - 1;
        }
        rollNo[j + 1] = keyRoll;
        name[j + 1] = keyName;
        sgpa[j + 1] = keySgpa;
    }
}

// Function to display the roll call list
void display(int rollNo[], string name[], float sgpa[], int n) {
    cout << "Roll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << rollNo[i] << "\t" << name[i] << "\t" << sgpa[i] << endl;
    }
}

int main() {
    int n = 15; // Number of students
    int rollNo[] = {12, 3, 9, 16, 1, 8, 7, 14, 4, 10, 15, 5, 2, 13, 6};
    string name[] = {"John", "Anya", "Peter", "Mary", "Alex", "Sara", "Henry", "James", "Lucy", "Kevin", "Sophia", "Liam", "Oliver", "Emma", "David"};
    float sgpa[] = {8.2, 7.5, 9.0, 6.8, 8.9, 7.2, 8.5, 9.1, 7.8, 8.7, 9.3, 6.9, 7.1, 8.6, 7.0};

    cout << "Original List:\n";
    display(rollNo, name, sgpa, n);

    // Sort by roll number
    insertionSort(rollNo, name, sgpa, n);

    cout << "\nSorted by Roll No (Ascending):\n";
    display(rollNo, name, sgpa, n);

    return 0;
}
