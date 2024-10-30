/*Assignment No.9a
Name-snehal uday shinde
PRN-123B1B264
Assignment Title:Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility: a. Add Party to Waitlist b. Seat Party c. Display Waitlist
*/

#include<iostream>
using namespace std;

// Node class to represent each party in the waitlist
class Node {
    public:
    string partyName; // Stores the name of the party
    Node* next;       // Pointer to the next party in the waitlist

    // Constructor to initialize the party name and set next to nullptr
    Node(string name) {
        partyName = name;
        next = nullptr;
    }
};

// RestaurantWaitlist class to manage the waitlist using a queue (FIFO)
class RestaurantWaitlist {
    Node* front; // Pointer to the front of the waitlist
    Node* rear;  // Pointer to the rear of the waitlist

    public:
    // Constructor to initialize an empty waitlist
    RestaurantWaitlist() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the waitlist is empty
    bool isEmpty() {
        return front == nullptr; // Waitlist is empty if front is null
    }

    // Function to add a new party to the waitlist
    void addParty(string PartyName) {
        Node* newNode = new Node(PartyName); // Create a new node with the party's name
        if (isEmpty()) {
            // If the waitlist is empty, both front and rear point to the new node
            front = rear = newNode;
        }
        else {
            // If waitlist is not empty, add the new node at the rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << PartyName << " has been added to the waitlist." << endl;
    }

    // Function to seat the party at the front of the waitlist
    void seatParty() {
        if (isEmpty()) {
            cout << "Waitlist is empty, no party to seat" << endl;
            return;
        }
        Node* temp = front; // Temporarily store the front node
        cout << front->partyName << " has been seated." << endl;
        front = front->next; // Move the front pointer to the next party
        if (front == nullptr) {
            // If the front is null after seating, the waitlist is now empty
            rear = nullptr;
        }
        delete temp; // Delete the old front node (the seated party)
    }

    // Function to display all parties currently in the waitlist
    void displayWaitlist() {
        if (isEmpty()) {
            cout << "Waitlist is empty." << endl;
            return;
        }
        Node* temp = front; // Start from the front of the waitlist
        cout << "Current Waitlist: " << endl;
        while (temp != nullptr) {
            // Loop through the waitlist and print each party's name
            cout << temp->partyName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    RestaurantWaitlist waitlist; // Create a waitlist object
    int choice;
    string partyName;

    do {
        // Display menu options
        cout << "\nRestaurantWaitlist system" << endl;
        cout << "1. Add Party to waitlist" << endl;
        cout << "2. Seat Party" << endl;
        cout << "3. Display Waitlist" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
        case 1:
            // Option to add a new party to the waitlist
            cout << "Enter party name: ";
            cin >> partyName;
            waitlist.addParty(partyName);
            break;
        case 2:
            // Option to seat the party at the front of the waitlist
            waitlist.seatParty();
            break;
        case 3:
            // Option to display the entire waitlist
            waitlist.displayWaitlist();
            break;
        case 4:
            // Option to exit the system
            cout << "Exiting system." << endl;
            break;
        default:
            // Handle invalid menu choices
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}
