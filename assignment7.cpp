/*Assignment No.7

Name-Snehal Uday Shinde
PRN-123B1B264
Assignment Title: Implement a browser history management system using a stack data structure to track the user's browsing history. The system should support the following functionalities: a. Add visited page b. Navigate back c. View current page d. Check if history is empty or not Assume no upper bound on number of pages visited.*/


#include <iostream>
using namespace std;

// Node class to represent each page in the browser history
class Node {
public:
    string url;    // Stores the URL of the page
    Node* next;    // Pointer to the next node in the stack

    // Constructor to create a node
    Node(string pageURL) {
        url = pageURL;
        next = nullptr;
    }
};

// BrowserHistory class to manage the stack of pages
class BrowserHistory {
private:
    Node* top;    // The top node in the stack (most recently visited page)

public:
    // Constructor to initialize the stack as empty
    BrowserHistory() {
        top = nullptr;
    }

    // Function to add a visited page (Push operation)
    void visitPage(string pageURL) {
        Node* newPage = new Node(pageURL);
        newPage->next = top;  // The new page points to the current top
        top = newPage;        // The new page becomes the top of the stack
        cout << "Visited: " << pageURL << endl;
    }

    // Function to navigate back (Pop operation)
    void back() {
        if (isEmpty()) {
            cout << "No history to go back." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;  // Move the top pointer to the next page in the history
        cout << "Navigating back from: " << temp->url << endl;
        delete temp;  // Free the memory of the removed page
    }

    // Function to view the current page (Peek operation)
    void currentPage() {
        if (isEmpty()) {
            cout << "No pages in history." << endl;
        } else {
            cout << "Current page: " << top->url << endl;
        }
    }

    // Function to check if the history is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    BrowserHistory history;

    // Visiting some pages
    history.visitPage("www.google.com");
    history.visitPage("www.github.com");
    history.visitPage("www.stackoverflow.com");

    // View the current page
    history.currentPage();  // Should display stackoverflow.com

    // Navigate back to the previous page
    history.back();  // Should go back from stackoverflow.com

    // View the current page
    history.currentPage();  // Should display github.com

    // Navigate back to the previous page
    history.back();  // Should go back from github.com

    // Check if history is empty
    if (history.isEmpty()) {
        cout << "History is empty." << endl;
    } else {
        cout << "History is not empty." << endl;
    }

    // Navigate back to the previous page (Should go back to google.com)
    history.back();

    // Try to navigate back again (No history left)
    history.back();  // Should display "No history to go back."

    return 0;
}
