/* Name-Snehal Uday Shinde.
   PRN-123B1B264.
c. Radix Sort to Find the First Ten Toppers Based on SGPA.*/
#include <iostream>
using namespace std;

int getMax(float sgpa[], int n) {
    float max = sgpa[0];
    for (int i = 1; i < n; i++) {
        if (sgpa[i] > max)
            max = sgpa[i];
    }
    return (int)(max * 10);  // Converting floating to int
}

void countSort(float sgpa[], int roll[], string name[], int n, int exp) {
    int outputRoll[15];
    string outputName[15];
    float outputSgpa[15];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(int(sgpa[i] * 10) / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (int(sgpa[i] * 10) / exp) % 10;
        outputRoll[count[index] - 1] = roll[i];
        outputName[count[index] - 1] = name[i];
        outputSgpa[count[index] - 1] = sgpa[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        roll[i] = outputRoll[i];
        name[i] = outputName[i];
        sgpa[i] = outputSgpa[i];
    }
}

void radixSort(float sgpa[], int roll[], string name[], int n) {
    int max = getMax(sgpa, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(sgpa, roll, name, n, exp);
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

    cout << "\nBefore Sorting by SGPA:\n";
    printList(roll, name, sgpa, n);

    radixSort(sgpa, roll, name, n);

    cout << "\nTop 10 Toppers (Radix Sort):\n";
    printList(roll, name, sgpa, 10);  // Only showing top 10

    return 0;
}