/*Assignment No.6

Name-Snehal Uday Shinde
PRN-123B1B264
Assignment Title: Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results. */

#include <iostream>
using namespace std;

// Node class to represent each term in the polynomial
class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    // Constructor to create a node
    Node(int coef, int exp) {
        coefficient = coef;
        exponent = exp;
        next = nullptr;
    }
};

// Polynomial class
class Polynomial {
private:
    Node* head;

public:
    // Constructor to initialize the head to null
    Polynomial() {
        head = nullptr;
    }

    // Method to insert a new term in descending order of exponents
    void insertTerm(int coef, int exp) {
        Node* newNode = new Node(coef, exp);

        // If the list is empty or the exponent of the new term is larger than the head
        if (head == nullptr || head->exponent < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->exponent > exp) {
                temp = temp->next;
            }
            
            if (temp->next != nullptr && temp->next->exponent == exp) {
                // Combine terms with the same exponent
                temp->next->coefficient += coef;
            } else {
                // Insert the new term in the correct position
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Method to add two polynomials
    Polynomial add(Polynomial p) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = p.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exponent == p2->exponent) {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }

        // If any terms are left in p1
        while (p1 != nullptr) {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }

        // If any terms are left in p2
        while (p2 != nullptr) {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }

    // Method to display the polynomial
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp != nullptr && temp->coefficient >= 0)
                cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    // Inserting terms for the first polynomial
    poly1.insertTerm(5, 2); // 5x^2
    poly1.insertTerm(4, 1); // 4x^1
    poly1.insertTerm(2, 0); // 2x^0

    // Inserting terms for the second polynomial
    poly2.insertTerm(5, 1); // 5x^1
    poly2.insertTerm(5, 0); // 5x^0

    cout << "First Polynomial: ";
    poly1.display();

    cout << "Second Polynomial: ";
    poly2.display();

    // Adding the two polynomials
    Polynomial result = poly1.add(poly2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}
