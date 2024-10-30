/*Assignment No:9b
Name-snehal uday shinde
PRN-123B1B264
Assignment Title:Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. The system should support the following operations using a circular queue data structure: a. Customer arrival b. Customer checkout c. Close Checkout Counter d. View customer.
*/

#include<iostream>
using namespace std;

// Class to represent a Customer
class Customer
{
    string name;  // Customer's name
    int mobileNo; // Customer's mobile number
    public:
    // Function to read customer details
    void read()
    {
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter customer mobile number: ";
        cin >> mobileNo;
    }

    // Function to display customer details
    void display()
    {
        cout << "Customer Name: " << name << ", Mobile Number: " << mobileNo << endl;
    }
};

// Class to represent the Customer Queue
class CustQueue
{
    Customer q[5]; // Array to store customers in the queue (size 5)
    int front, rear; // Variables to track front and rear of the queue

    public:
    // Constructor to initialize front and rear
    CustQueue()
    {
        front = rear = -1; // Queue is initially empty
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (rear == 5 - 1); // If rear has reached the last index, queue is full
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 || front > rear); // Queue is empty if front is -1 or front has crossed rear
    }

    // Function to add a new customer to the queue
    void addNewCust()
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot add more customers.\n"; // Check if the queue is full
        }
        else
        {
            if (front == -1)
                front = 0; // If adding the first customer, set front to 0
            rear++; // Move rear forward to make space for the new customer
            q[rear].read(); // Read the new customer's details
        }
    }

    // Function to check out a customer from the queue
    void customerCheckedOut()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue.\n"; // If queue is empty, no customer to check out
        }
        else
        {
            cout << "Customer checking out: \n";
            q[front].display(); // Display the customer at the front of the queue
            front++; // Move the front forward to the next customer
        }
    }

    // Function to close the checkout counter and serve all remaining customers
    void closeCheckoutCounter()
    {
        if (isEmpty())
        {
            cout << "No customers to serve.\n"; // If queue is empty, no customers left
        }
        else
        {
            cout << "Closing the counter. Serving all remaining customers:\n";
            while (!isEmpty())
            {
                customerCheckedOut(); // Serve each customer until the queue is empty
            }
        }
    }

    // Function to view all customers currently in the queue
    void viewCustomer()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue.\n"; // If queue is empty, no customers to display
        }
        else
        {
            cout << "Customers in the queue:\n";
            for (int i = front; i <= rear; i++) // Loop through all customers from front to rear
            {
                q[i].display(); // Display each customer's details
            }
        }
    }
};

// Main function to test the queue functionality
int main()
{
    CustQueue queue; // Create an object of CustQueue
    int choice;

    do
    {
        // Display the menu
        cout << "\n1. Add new customer\n";
        cout << "2. Customer checked out\n";
        cout << "3. View customers in queue\n";
        cout << "4. Close checkout counter\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case to handle different menu choices
        switch (choice)
        {
            case 1:
                queue.addNewCust(); // Add a new customer
                break;
            case 2:
                queue.customerCheckedOut(); // Check out the customer at the front
                break;
            case 3:
                queue.viewCustomer(); // View all customers in the queue
                break;
            case 4:
                queue.closeCheckoutCounter(); // Serve all remaining customers and close the counter
                break;
            case 5:
                cout << "Exiting...\n"; // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Handle invalid choice
        }

    } while (choice != 5); // Loop until the user chooses to exit

    return 0;
}
