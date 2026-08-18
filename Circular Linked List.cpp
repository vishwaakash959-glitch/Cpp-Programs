#include <iostream>

// Definition of a Node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Definition of the Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor initializes an empty list
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        // Case 1: If the list is empty
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself to maintain circularity
            return;
        }

        // Case 2: Traverse to find the last node
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        // Link the old last node to the new node
        temp->next = newNode;
        // Link the new node back to the head
        newNode->next = head;
    }

    // Function to traverse and print the circular list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        // Use a do-while loop because the condition (temp != head) 
        // is false at the very beginning of standard iterations
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        
        std::cout << "(back to head: " << head->data << ")" << std::endl;
    }

    // Destructor to prevent memory leaks by freeing allocated memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode = nullptr;

        // Break the circle to safely delete nodes sequentially
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nullptr; // Terminate loop structure

        // Delete elements sequentially
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    CircularLinkedList cll;

    // Insert data elements
    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertEnd(30);
    cll.insertEnd(40);

    // Print the sequence
    std::cout << "Circular Linked List elements: " << std::endl;
    cll.display();

    return 0;
}
