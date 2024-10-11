#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CList {
private:
    Node* head;

public:
    // Constructor: Initializes an empty list
    CList() {
        head = nullptr;
    }

    // Checks if the list is empty or not
    bool emptyList() {
        return head == nullptr;
    }

    // Inserts a new node at the start of the list
    void insert_begin(int value) {
        Node* newNode = new Node(value);
        if (emptyList()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Inserts a new node at the end of the list
    void insert_end(int value) {
        Node* newNode = new Node(value);
        if (emptyList()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Inserts a new node with value ‘value’ at position ‘pos’ in the list (restrict pos=1)
    void insert_at(int pos, int value) {
        if (pos == 1) {
            cout << "Position 1 is restricted. Use insert_begin() instead." << endl;
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 1;

        // Traverse to the node before the desired position
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        // If the position is invalid (out of range)
        if (count != pos - 1) {
            cout << "Invalid position!" << endl;
            delete newNode;  // Free memory if position is invalid
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Deletes a node from the beginning of the list
    void delete_begin() {
        if (emptyList()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
        }
        else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    // Deletes a node from the end of the list
    void delete_end() {
        if (emptyList()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
        }
        else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = head;
            delete delNode;
        }
    }

    // Deletes a node from position ‘pos’ (restrict pos=1)
    void deleteNode(int pos) {
        if (pos == 1) {
            cout << "Position 1 is restricted. Use delete_begin() instead." << endl;
            return;
        }

        if (emptyList()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        int count = 1;

        // Traverse to the node before the position to be deleted
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        // If the position is invalid (out of range)
        if (temp->next == head || count != pos - 1) {
            cout << "Invalid position!" << endl;
        }
        else {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
    }

    // Displays the values stored in the list
    void traverse() {
        if (emptyList()) {
            cout << "(empty)" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Example usage
int main() {
    CList clist;

    // Inserting values at the beginning and end
    clist.insert_begin(10);  // Insert at the beginning
    clist.insert_end(20);    // Insert at the end
    clist.insert_end(30);    // Insert at the end

    // Display the list
    clist.traverse();  // Output: 10 20 30

    // Inserting at position (restrictions apply)
    clist.insert_at(2, 15);  // Insert 15 at position 2
    clist.traverse();  // Output: 10 15 20 30

    // Deleting nodes
    clist.delete_begin();  // Delete the first node
    clist.traverse();  // Output: 15 20 30

    clist.delete_end();  // Delete the last node
    clist.traverse();  // Output: 15 20

    clist.deleteNode(2);  // Delete node at position 2
    clist.traverse();  // Output: 15

    return 0;
}