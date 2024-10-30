/*Assignment No.4

Name-Snehal Uday Shinde
PRN-123B1B264
Assignment Title: Implement a simple text editor application using a doubly linked list to manage the text buffer. Text editor should support the following functionalities: a. Insert text b. Delete text c. Display text d. Search text e. Print text in reverse.*/


#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    // Constructor for creating a new node
    Node(char d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class TextEditor {
private:
    Node* head;  // Head of the doubly linked list
    Node* tail;  // Tail of the doubly linked list

public:
    // Constructor for initializing the text buffer
    TextEditor() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert text (character by character)
    void insertText(string text) {
        for (char ch : text) {
            Node* newNode = new Node(ch);

            // If the list is empty
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        cout << "Text inserted successfully.\n";
    }

    // Function to delete text from the end (deleting last N characters)
    void deleteText(int n) {
        if (!tail) {
            cout << "Text buffer is empty.\n";
            return;
        }

        while (n-- && tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr; // If the list is now empty
            delete temp;
        }
        cout << "Deleted " << n << " characters from the end.\n";
    }

    // Function to display the entire text
    void displayText() {
        if (!head) {
            cout << "Text buffer is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Current text: ";
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for a character in the text
    void searchText(char ch) {
        if (!head) {
            cout << "Text buffer is empty, nothing to search.\n";
            return;
        }

        Node* temp = head;
        int position = 1;
        bool found = false;

        while (temp) {
            if (temp->data == ch) {
                cout << "Character '" << ch << "' found at position: " << position << endl;
                found = true;
            }
            temp = temp->next;
            position++;
        }

        if (!found) {
            cout << "Character '" << ch << "' not found in the text.\n";
        }
    }

    // Function to print the text in reverse order
    void printReverse() {
        if (!tail) {
            cout << "Text buffer is empty.\n";
            return;
        }

        Node* temp = tail;
        cout << "Text in reverse: ";
        while (temp) {
            cout << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;

    // Insert text into the editor
    editor.insertText("Hello World!");

    // Display the current text
    editor.displayText();

    // Search for a character
    editor.searchText('o');

    // Delete the last 6 characters ("World!")
    editor.deleteText(6);

    // Display the current text
    editor.displayText();

    // Print the current text in reverse
    editor.printReverse();
return 0;
}
    
