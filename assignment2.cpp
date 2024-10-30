/*Assignment No.2

Name-Snehal Uday Shinde.
PRN-123B1B264
Assignment Title: Consider Employee database of PCCOE (at least 20 records). Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary. a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort b. Arrange list of Employee alphabetically using Merge Sort.*/

#include <iostream>
using namespace std;

const int MAX = 20;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Quick Sort - Sorting based on EMP-ID
int partition(int empID[], string empName[], float empSalary[], int low, int high) {
    int pivot = empID[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (empID[j] < pivot) {
            i++;
            swap(empID[i], empID[j]);
            swap(empName[i], empName[j]);
            swap(empSalary[i], empSalary[j]);
        }
    }
    swap(empID[i + 1], empID[high]);
    swap(empName[i + 1], empName[high]);
    swap(empSalary[i + 1], empSalary[high]);
    return (i + 1);
}

void quickSort(int empID[], string empName[], float empSalary[], int low, int high) {
    if (low < high) {
        int pi = partition(empID, empName, empSalary, low, high);
        quickSort(empID, empName, empSalary, low, pi - 1);
        quickSort(empID, empName, empSalary, pi + 1, high);
    }
}

// Merge Sort - Sorting based on EMP-Name alphabetically
void merge(string empName[], int empID[], float empSalary[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string leftName[MAX], rightName[MAX];
    int leftID[MAX], rightID[MAX];
    float leftSalary[MAX], rightSalary[MAX];

    for (int i = 0; i < n1; i++) {
        leftName[i] = empName[left + i];
        leftID[i] = empID[left + i];
        leftSalary[i] = empSalary[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightName[j] = empName[mid + 1 + j];
        rightID[j] = empID[mid + 1 + j];
        rightSalary[j] = empSalary[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftName[i] <= rightName[j]) {
            empName[k] = leftName[i];
            empID[k] = leftID[i];
            empSalary[k] = leftSalary[i];
            i++;
        } else {
            empName[k] = rightName[j];
            empID[k] = rightID[j];
            empSalary[k] = rightSalary[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        empName[k] = leftName[i];
        empID[k] = leftID[i];
        empSalary[k] = leftSalary[i];
        i++;
        k++;
    }

    while (j < n2) {
        empName[k] = rightName[j];
        empID[k] = rightID[j];
        empSalary[k] = rightSalary[j];
        j++;
        k++;
    }
}

void mergeSort(string empName[], int empID[], float empSalary[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(empName, empID, empSalary, left, mid);
        mergeSort(empName, empID, empSalary, mid + 1, right);
        merge(empName, empID, empSalary, left, mid, right);
    }
}

// Function to display employee details
void displayEmployees(int empID[], string empName[], float empSalary[], int n) {
    cout << "\nEMP-ID\tEMP-Name\tEMP-Salary\n";
    for (int i = 0; i < n; i++) {
        cout << empID[i] << "\t" << empName[i] << "\t\t" << empSalary[i] << endl;
    }
}

int main() {
    int empID[MAX] = {1005, 1001, 1003, 1002, 1004, 1020, 1015, 1006, 1010, 1009,
                      1018, 1011, 1016, 1019, 1012, 1017, 1008, 1007, 1013, 1014};
    string empName[MAX] = {"John", "Alice", "Bob", "David", "Eve", "Grace", "Hank", "Ivy", "Jack", "Kate",
                           "Liam", "Mona", "Nora", "Owen", "Paul", "Quinn", "Rita", "Sam", "Tom", "Uma"};
    float empSalary[MAX] = {50000, 45000, 55000, 48000, 51000, 52000, 53000, 49000, 47000, 46000,
                            56000, 60000, 61000, 62000, 63000, 64000, 65000, 66000, 67000, 68000};

    int n = 20;

    cout << "Original Employee List:\n";
    displayEmployees(empID, empName, empSalary, n);

    // Sorting by EMP-ID using Quick Sort
    quickSort(empID, empName, empSalary, 0, n - 1);
    cout << "\nEmployee List sorted by EMP-ID (Quick Sort):\n";
    displayEmployees(empID, empName, empSalary, n);

    // Sorting by EMP-Name using Merge Sort
    mergeSort(empName, empID, empSalary, 0, n - 1);
    cout << "\nEmployee List sorted by EMP-Name (Merge Sort):\n";
    displayEmployees(empID, empName, empSalary, n);

    return 0;
}
