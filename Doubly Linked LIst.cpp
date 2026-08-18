#include <iostream>

// 1. Node Structure Definitions
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// 2. Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up heap memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert at the front of the list
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at the back of the list
    void insertBack(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete a node by its value
    void deleteValue(int value) {
        if (head == nullptr) return;

        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // Value not found
        if (current == nullptr) return;

        // If it's the head node
        if (current == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr; // List became empty
        }
        // If it's the tail node
        else if (current == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
            else head = nullptr;
        }
        // If it's a middle node
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Traverse and print from Head to Tail
    void displayForward() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Traverse and print from Tail to Head
    void displayBackward() const {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertBack(10);
    dll.insertBack(20);
    dll.insertFront(5);
    dll.insertBack(30);

    std::cout << "Forward Traversal:  ";
    dll.displayForward(); // Output: 5 <-> 10 <-> 20 <-> 30 <-> NULL

    std::cout << "Backward Traversal: ";
    dll.displayBackward(); // Output: 30 <-> 20 <-> 10 <-> 5 <-> NULL

    dll.deleteValue(20);
    std::cout << "After Deleting 20:  ";
    dll.displayForward(); // Output: 5 <-> 10 <-> 30 <-> NULL

    return 0;
}
