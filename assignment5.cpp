/*Assignment No.5

Name-Snehal Uday Shinde
PRN-123B1B264
Assignment Title: Implement a navigation system for a delivery service using a circular linked list to represent routes. The navigation system should support the following functionalities: a. Add route b. Remove route c. Display route. without using vector and struct using node and class*/

#include <iostream>
using namespace std;

// Node class to represent each route
class Node {
public:
    string route; // name of the route
    Node* next;   // pointer to the next node

    // Constructor
    Node(string r) : route(r), next(nullptr) {}
};

// Circular linked list class
class CircularLinkedList {
private:
    Node* last;  // points to the last node in the circular linked list

public:
    // Constructor to initialize an empty list
    CircularLinkedList() : last(nullptr) {}

    // Function to add a new route
    void addRoute(string routeName) {
        Node* newNode = new Node(routeName);

        // Case 1: Empty list
        if (last == nullptr) {
            last = newNode;
            last->next = last; // circular link
        }
        // Case 2: Non-empty list
        else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Route added: " << routeName << endl;
    }

    // Function to remove a route by name
    void removeRoute(string routeName) {
        if (last == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        Node* current = last->next;
        Node* previous = last;

        // Traverse to find the route to remove
        do {
            if (current->route == routeName) {
                // Case 1: Only one route in the list
                if (current == last && current->next == last) {
                    delete current;
                    last = nullptr;
                }
                // Case 2: Removing the last route
                else if (current == last) {
                    previous->next = last->next;
                    last = previous;
                    delete current;
                }
                // Case 3: Removing any other route
                else {
                    previous->next = current->next;
                    delete current;
                }
                cout << "Route removed: " << routeName << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != last->next);

        cout << "Route not found: " << routeName << endl;
    }

    // Function to display all routes
    void displayRoutes() {
        if (last == nullptr) {
            cout << "No routes to display." << endl;
            return;
        }

        Node* current = last->next; // Start from the first node
        cout << "Routes: ";
        do {
            cout << current->route << " ";
            current = current->next;
        } while (current != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList routeList;

    // Add routes
    routeList.addRoute("Route A");
    routeList.addRoute("Route B");
    routeList.addRoute("Route C");

    // Display routes
    routeList.displayRoutes();

    // Remove a route
    routeList.removeRoute("Route B");

    // Display routes again
    routeList.displayRoutes();

    // Remove a route that doesn't exist
    routeList.removeRoute("Route D");

    // Remove the last route
    routeList.removeRoute("Route A");
    routeList.removeRoute("Route C");

    // Display routes again
    routeList.displayRoutes();

    return 0;
}
