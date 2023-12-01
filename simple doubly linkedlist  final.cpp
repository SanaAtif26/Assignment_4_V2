#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (!head) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (!tail) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void insertAt(int value, int index) {
        if (index <= 0) {
            addFirst(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            return; // Index out of bounds
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    int max() {
        if (!head) {
            return INT_MIN;
        }
        int maxValue = head->data;
        Node* current = head->next;
        while (current) {
            if (current->data > maxValue) {
                maxValue = current->data;
            }
            current = current->next;
        }
        return maxValue;
    }

    double average() {
        if (!head) {
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        Node* current = head;
        while (current) {
            total += current->data;
            ++count;
            current = current->next;
        }
        return total / count;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

// Driver code
int main() {
    DoublyLinkedList doublyLinkedList;

    // Adding elements to the doubly linked list
    doublyLinkedList.addLast(1);
    doublyLinkedList.addLast(2);
    doublyLinkedList.addLast(3);
    doublyLinkedList.addLast(2);
    doublyLinkedList.addLast(1);

    std::cout << "Original Doubly Linked List:" << std::endl;
    Node* current = doublyLinkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    doublyLinkedList.addFirst(0);
    doublyLinkedList.deleteLast();
    doublyLinkedList.insertAt(6, 3);

    std::cout << "Modified Doubly Linked List:" << std::endl;
    current = doublyLinkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Search 3: " << (doublyLinkedList.search(3) ? "Found" : "Not Found") << std::endl;

    std::cout << "Count Nodes: " << doublyLinkedList.countNodes() << std::endl;

    std::cout << "Max Value: " << doublyLinkedList.max() << std::endl;

    std::cout << "Average Value: " << doublyLinkedList.average() << std::endl;

    doublyLinkedList.reverse();
    std::cout << "Reversed Doubly Linked List:" << std::endl;
    current = doublyLinkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Detect Loop: " << (doublyLinkedList.detectLoop() ? "Yes" : "No") << std::endl;

    return 0;
}
//=======================================TIME AND SPACE COMLEXITY OF ALL FUNCTIONS:===========================
//1)linkedlist constructor:
//time complexity:0(1)
//space complexity:0(1)
//2)add first(int value):
//time complexity:0(1)
//space complexity:0(1)
//3)addlast(int value)
//time complexity:0(1)
//space complexity:0(1)
//4)delete first:
//time comlexity:0(1)
//space complexity:0(1)
//5)delete last(int value):
//time complexity:0(1)
//space complexity:0(1)
//6)insertat (intvalue,int index)
//time complexity:0(1)
//space complexity:0(1)
//7)search(int value)
//time complexity: 0(n)
//space complexity:0(1)
//8)count nodes():
//time complexity:0(n)
//space complexity:0(1)
//9)max():
//time complexity:0(n)
//space complxity:0(1)
//10)average():
//time complexity:0(n)
//space complexity:0(1)
//10)reverse():
//time complexity:0(n)
//space comlexity:0(1)
//11)detect loop():
//time complexity:0(n)
//space complexity:0(1)
//===============================completed all functions time and space comlexity===================//
