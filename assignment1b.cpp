/*Name-Snehal Uday Shinde.
PRN-123B1B264.
b. Shell Sort to Sort by Name (Alphabetically)*/
#include <iostream>
using namespace std;

void shellSort(int roll[], string name[], float sgpa[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string tempName = name[i];
            int tempRoll = roll[i];
            float tempSgpa = sgpa[i];
            int j;
            for (j = i; j >= gap && name[j - gap] > tempName; j -= gap) {
                name[j] = name[j - gap];
                roll[j] = roll[j - gap];
                sgpa[j] = sgpa[j - gap];
            }
            name[j] = tempName;
            roll[j] = tempRoll;
            sgpa[j] = tempSgpa;
        }
    }
}
void printList(int roll[], string name[], float sgpa[], int n) {
    cout << "Roll No\tName\t\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << roll[i] << "\t" << name[i] << "\t" << sgpa[i] << endl;
    }
}

int main() {
    int roll[] = {15, 3, 10, 12, 5, 1, 14, 8, 7, 6, 9, 2, 11, 4, 13};
    string name[] = {"Rohan", "Akshay", "Neha", "Pranav", "Bhavesh", "Shreya", "Amit", "Isha", "Nina", "Rahul", "Karan", "Sonal", "Priya", "Anil", "Manish"};
    float sgpa[] = {8.5, 7.2, 9.1, 7.8, 6.9, 8.9, 9.3, 7.5, 8.2, 6.7, 7.4, 9.0, 7.3, 8.1, 9.5};
    int n = sizeof(roll) / sizeof(roll[0]);

    cout << "\nBefore Sorting by Name:\n";
    printList(roll, name, sgpa, n);

    shellSort(roll, name, sgpa, n);

    cout << "\nAfter Sorting by Name (Shell Sort):\n";
    printList(roll, name, sgpa, n);

    return 0;
}
