/*Assignment No:11
Name-snehal uday shinde
PRN-123B1B264
Assignment Title:Consider an employee database of N employees. Make use of a hash table implementation to quickly look up the employer's id number.
*/
#include <iostream>
#include <string>
#define size 10
using namespace std;

class Employee {
    public:
    int empid;
    string name;
    string phno;
    void read() {
        cout << "EMPLOYEE DETAILS" << endl;
        cout << "NAME: ";
        cin >> name;
        cout << "ID: ";
        cin >> empid;
        cout << "PHONE NUMBER: ";
        cin >> phno;
    }

    void display() {
        cout << "EMPLOYEE NAME: " << name << endl;
        cout << "EMPLOYEE ID: " << empid << endl;
        cout << "PHONE NUMBER: " << phno << endl;
    }

    int getEmpID() {
        return empid;
    }

    // Added method to check if employee is empty
    bool isEmpty() {
        return empid == 0; // Assuming empid is always greater than 0 for valid employees
    }
};

class HTEmployee {
public:
    Employee HT[size];
    int flag[size];

    HTEmployee() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0; // 0 means empty
        }
    }

    void insert() {
        Employee newR;
        newR.read();
        int id = newR.getEmpID();
        int hashV = id % size;

        if (flag[hashV] == 0) {
            HT[hashV] = newR;
            flag[hashV] = 1; // Mark the slot as occupied
        } else {
            for (int i = 1; i < size; i++) {
                int pos = (hashV + i) % size;
                if (flag[pos] == 0) {
                    HT[pos] = newR;
                    flag[pos] = 1; // Mark the slot as occupied
                    return; // Exit after insertion
                }
            }
            cout << "Hash table is full. Cannot insert new employee." << endl;
        }
    }

    void display() {
        cout << "EMPLOYEE TABLE" << endl;
        cout << "NAME\t\tEMP_ID\t\tPH_NO" << endl;
        for (int i = 0; i < size; i++) {
            if (flag[i] == 1) { // Only display occupied slots
                cout << HT[i].name << "\t\t" << HT[i].getEmpID() << "\t\t" << HT[i].phno << endl;
            }
        }
    }

    void search() {
        int searchID;
        cout << "ENTER EMPLOYEE ID TO BE SEARCHED: ";
        cin >> searchID;
        int hashV = searchID % size;

        for (int i = 0; i < size; i++) {
            int pos = (hashV + i) % size;
            if (flag[pos] == 1 && HT[pos].getEmpID() == searchID) {
                HT[pos].display(); // Display the found employee
                return; // Exit after finding
            }
        }
        cout << "Employee with ID " << searchID << " not found." << endl;
    }
};

int main() {
    HTEmployee ht;
    int choice;
    cout << "------- EMPLOYEE DATABASE -------" << endl;
    do {
        cout << "1. INSERT EMPLOYEE DETAILS" << endl;
        cout << "2. DISPLAY EMPLOYEE DETAILS" << endl;
        cout << "3. SEARCH EMPLOYEE DETAILS" << endl;
        cout << "4. EXIT" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "INSERT EMPLOYEE DETAILS" << endl;
                ht.insert();
                break;

            case 2:
                cout << "DISPLAY EMPLOYEE DETAILS" << endl;
                ht.display();
                break;

            case 3:
                cout << "SEARCH EMPLOYEE DETAILS" << endl;
                ht.search();
                break;
            
            case 4:
                cout << "EXITING THE PROGRAM... THANK YOU!!" << endl;
                exit(0);
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}