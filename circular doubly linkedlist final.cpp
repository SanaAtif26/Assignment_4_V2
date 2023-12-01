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

class CircularDoublyLinkedList {
public:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link
            newNode->prev = head;  // Circular link
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
            head = newNode;
        }
    }

    void addLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link
            newNode->prev = head;  // Circular link
        } else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;  // Circular link
            head->prev = newNode;
        }
    }

    void deleteFirst() {
        if (!head) {
            return;
        }
        Node* last = head->prev;
        if (head == last) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            last->next = head;
            head->prev = last;
            delete temp;
        }
    }

    void deleteLast() {
        if (!head) {
            return;
        }
        Node* last = head->prev;
        if (head == last) {
            delete head;
            head = nullptr;
        } else {
            Node* secondLast = last->prev;
            secondLast->next = head;
            head->prev = secondLast;
            delete last;
        }
    }

    void insertAt(int value, int index) {
        if (index <= 0) {
            addFirst(value);
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link
            newNode->prev = head;  // Circular link
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    bool search(int value) {
        if (!head) {
            return false;
        }
        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    int countNodes() {
        if (!head) {
            return 0;
        }
        int count = 0;
        Node* current = head;
        do {
            ++count;
            current = current->next;
        } while (current != head);
        return count;
    }

    int max() {
        if (!head) {
            return INT_MIN;
        }
        int maxValue = head->data;
        Node* current = head->next;
        do {
            if (current->data > maxValue) {
                maxValue = current->data;
            }
            current = current->next;
        } while (current != head);
        return maxValue;
    }

    double average() {
        if (!head) {
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        Node* current = head;
        do {
            total += current->data;
            ++count;
            current = current->next;
        } while (current != head);
        return total / count;
    }

    void reverse() {
        if (!head) {
            return;
        }
        Node* current = head;
        do {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        } while (current != head);
        head = head->prev;
    }

    bool detectLoop() {
        if (!head) {
            return false;
        }
        Node* slow = head;
        Node* fast = head;
        do {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        return true;
    }
};

// Driver code
int main() {
    CircularDoublyLinkedList circularList;

    // Adding elements to the circular doubly linked list
    circularList.addLast(1);
    circularList.addLast(2);
    circularList.addLast(3);
    circularList.addLast(4);

    std::cout << "Original Circular Doubly Linked List:" << std::endl;
    Node* current = circularList.head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != circularList.head);
    std::cout << std::endl;

    circularList.addFirst(0);
    circularList.deleteLast();
    circularList.insertAt(6, 3);

    std::cout << "Modified Circular Doubly Linked List:" << std::endl;
    current = circularList.head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != circularList.head);
    std::cout << std::endl;

    std::cout << "Search 3: " << (circularList.search(3) ? "Found" : "Not Found") << std::endl;

    std::cout << "Count Nodes: " << circularList.countNodes() << std::endl;

    std::cout << "Max Value: " << circularList.max() << std::endl;

    std::cout << "Average Value: " << circularList.average() << std::endl;

    circularList.reverse();
    std::cout << "Reversed Circular Doubly Linked List:" << std::endl;
    current = circularList.head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != circularList.head);
    std::cout << std::endl;

    std::cout << "Detect Loop: " << (circularList.detectLoop() ? "Yes" : "No") << std::endl;

    return 0;
}
//=====================TIME AND SPACE COMLEXITY OFF ALL FUNCIONS========================//


//circularDoublyLinkedList constructor:
//1)addFirst(int value):
//Time Complexity: O(1)
//Space Complexity: O(1)
//2)addLast(int value):
//Time Complexity: O(1)
//Space Complexity: O(1)
//3)deleteFirst():
//Time Complexity: O(1)
//Space Complexity: O(1)
//4)deleteLast():
//Time Complexity: O(1)
//Space Complexity: O(1)
//5)insertAt(int value, int index):
//Time Complexity: O(n)
//Space Complexity: O(1)
//6)search(int value):
//Time Complexity: O(n)
//Space Complexity: O(1)
//7)countNodes():
//Time Complexity: O(n)
//Space Complexity: O(1)
//8)max():
//Time Complexity: O(n)
//Space Complexity: O(1)
//9)average():
//Time Complexity: O(n)
//Space Complexity: O(1)
//10)reverse():
//Time Complexity: O(n)
//Space Complexity: O(1)
//11)detectLoop():
//Time Complexity: O(n)
//Space Complexity: O(1)
//================================completed all functions time and space complexities=================//
