/*Assignment No:10
Name-snehal uday shinde
PRN-123B1B264
Assignment Title:Implement a job scheduling system for a manufacturing plant using a double-ended queue. The system needs to efficiently manage the processing of jobs on various machines throughout the plant. Each job has a Job_priority. The system should support the following operations: a. Add Job b. Remove Job c. Display Job d. Search Job
*/
#include<iostream>
#include<string>
using namespace std;

class Job {
    string nameofJob;
    int priority, time;
public:
    Job *prev, *next;  // Pointers to previous and next Jobs
    Job() : nameofJob(""), priority(0), time(0), prev(NULL), next(NULL) {}
    
    void readJob() {
        cout << "Enter Job Name: ";
        cin >> nameofJob;
        cout << "Enter Job Priority: ";
        cin >> priority;
        cout << "Enter Time Required (in minutes): ";
        cin >> time;
    }

    void displayJob() {
        cout << "Job Name: " << nameofJob << ", Priority: " << priority 
             << ", Time: " << time << " minutes\n";
    }

    string getName() { return nameofJob; }
    int getPriority() { return priority; }
};

class Deque {
    Job *front, *rear;
public:
    Deque() : front(NULL), rear(NULL) {}

    // Insert job at the front of deque
    void insertFront() {
        Job *newJob = new Job;
        newJob->readJob();

        if (front == NULL) {
            front = rear = newJob;
        } else {
            newJob->next = front;
            front->prev = newJob;
            front = newJob;
        }
    }

    // Insert job at the rear of deque
    void insertBack() {
        Job *newJob = new Job;
        newJob->readJob();

        if (rear == NULL) {
            rear = front = newJob;
        } else {
            newJob->prev = rear;
            rear->next = newJob;
            rear = newJob;
        }
    }

    // Delete job from the front of deque
    void deleteFront() {
        if (front == NULL) {
            cout << "Deque is empty, no job to delete.\n";
            return;
        }

        Job *temp = front;
        front = front->next;

        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;  // If deque becomes empty
        }

        delete temp;
        cout << "Job deleted from front.\n";
    }

    // Delete job from the rear of deque
    void deleteBack() {
        if (rear == NULL) {
            cout << "Deque is empty, no job to delete.\n";
            return;
        }

        Job *temp = rear;
        rear = rear->prev;

        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL;  // If deque becomes empty
        }

        delete temp;
        cout << "Job deleted from back.\n";
    }

    // Display all jobs in deque
    void displayAll() {
        if (front == NULL) {
            cout << "No jobs in the deque.\n";
            return;
        }

        Job *temp = front;
        cout << "Jobs in deque:\n";
        while (temp != NULL) {
            temp->displayJob();
            temp = temp->next;
        }
    }

    // Search job by name or priority
    void searchJob(string name) {
        if (front == NULL) {
            cout << "No jobs to search.\n";
            return;
        }

        Job *temp = front;
        bool found = false;
        while (temp != NULL) {
            if (temp->getName() == name) {
                cout << "Job found:\n";
                temp->displayJob();
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Job with name " << name << " not found.\n";
        }
    }

    void searchJob(int priority) {
        if (front == NULL) {
            cout << "No jobs to search.\n";
            return;
        }

        Job *temp = front;
        bool found = false;
        while (temp != NULL) {
            if (temp->getPriority() == priority) {
                cout << "Job found:\n";
                temp->displayJob();
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Job with priority " << priority << " not found.\n";
        }
    }
};

int main() {
    Deque jobQueue;
    int choice;
    string jobName;
    int jobPriority;

    do {
        cout << "\n--- Job Scheduling System ---\n";
        cout << "1. Add Job at Front\n2. Add Job at Back\n3. Delete Job from Front\n4. Delete Job from Back\n";
        cout << "5. Display All Jobs\n6. Search Job by Name\n7. Search Job by Priority\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                jobQueue.insertFront();
                break;
            case 2:
                jobQueue.insertBack();
                break;
            case 3:
                jobQueue.deleteFront();
                break;
            case 4:
                jobQueue.deleteBack();
                break;
            case 5:
                jobQueue.displayAll();
                break;
            case 6:
                cout << "Enter Job Name to search: ";
                cin >> jobName;
                jobQueue.searchJob(jobName);
                break;
            case 7:
                cout << "Enter Job Priority to search: ";
                cin >> jobPriority;
                jobQueue.searchJob(jobPriority);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
