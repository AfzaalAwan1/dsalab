#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class HList {
private:
    Node* head;  // Dummy head node

public:
    HList() {
        head = new Node(0);  // Initialize the dummy head node with a default value
    }

    // Checks if the list is empty or not
    bool emptyList() {
        return head->next == nullptr;
    }

    // Inserts a new node with value ‘newV’ after node with value ‘oldV’ in the list
    void insert_after(int oldV, int newV) {
        Node* temp = head->next;
        while (temp != nullptr && temp->data != oldV) {
            temp = temp->next;
        }
        if (temp != nullptr) {  // oldV found
            Node* newNode = new Node(newV);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else {
            cout << "Value " << oldV << " not found in the list." << endl;
        }
    }

    // Inserts a new node at the start of the list
    void insert_begin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }

    // Inserts a new node at the end of the list
    void insert_end(int value) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        temp->next = newNode;
    }

    // Deletes a node of value ‘val’ from the list
    void delete_Node(int val) {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
        else {
            cout << "Value " << val << " not found in the list." << endl;
        }
    }

    // Deletes a node from the beginning of the list
    void delete_begin() {
        if (emptyList()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* delNode = head->next;
        head->next = head->next->next;
        delete delNode;
    }

    // Deletes a node from the end of the list
    void delete_end() {
        if (emptyList()) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = nullptr;
        delete delNode;
    }

    // Displays the values stored in the list
    void traverse() {
        Node* temp = head->next;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    HList list;

    list.insert_begin(10);  // Insert at the beginning
    list.insert_end(20);    // Insert at the end
    list.insert_after(10, 15);  // Insert 15 after 10
    list.traverse();  // Output: 10 15 20

    list.delete_begin();  // Delete the first node
    list.traverse();  // Output: 15 20

    list.delete_Node(15);  // Delete node with value 15
    list.traverse();  // Output: 20

    list.delete_end();  // Delete the last node
    list.traverse();  // Output: (empty)

    return 0;
}