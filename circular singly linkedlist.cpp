#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularSinglyLinkedList {
public:
    Node* head;

public:
    CircularSinglyLinkedList() {
        head = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
    }

    void addLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;  // Circular link
        }
    }

    void deleteFirst() {
        if (!head) {
            return;
        }
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        if (head == last) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    void deleteLast() {
        if (!head) {
            return;
        }
        Node* last = head;
        Node* secondLast = nullptr;
        while (last->next != head) {
            secondLast = last;
            last = last->next;
        }
        if (head == last) {
            delete head;
            head = nullptr;
        } else {
            secondLast->next = head;
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
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
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
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);
        head = prev;
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
    CircularSinglyLinkedList circularList;

    // Adding elements to the circular linked list
    circularList.addLast(1);
    circularList.addLast(2);
    circularList.addLast(3);
    circularList.addLast(4);

    std::cout << "Original Circular Linked List:" << std::endl;
    Node* current = circularList.head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != circularList.head);
    std::cout << std::endl;

    circularList.addFirst(0);
    circularList.deleteLast();
    circularList.insertAt(6, 3);

    std::cout << "Modified Circular Linked List:" << std::endl;
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
    std::cout << "Reversed Circular Linked List:" << std::endl;
    current = circularList.head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != circularList.head);
    std::cout << std::endl;

    std::cout << "Detect Loop: " << (circularList.detectLoop() ? "Yes" : "No") << std::endl;

    return 0;
}
//===========================TIME COMPLEXITY FROM ALL FUNCTIONS==============================//
//1)addFirst(int value):
//Time Complexity: O(n)
//Space Complexity: O(1)
//2)addLast(int value):
//Time Complexity: O(n)
//Space Complexity: O(1)
//3)deleteFirst():
//Time Complexity: O(n)
//Space Complexity: O(1)
//4)deleteLast():
//Time Complexity: O(n),
//Space Complexity: O(1)
//5)insertAt(int value, int index):
//Time Complexity: O(n)
//Space Complexity: O(1)
//6)search(int value):
//Time Complexity: O(n)
//Space Complexity: O(1)
//7)countNodes()
//Time Complexity: O(n)
//Space Complexity: O(1)
//8)max():
//Time Complexity: O(n)
//Space Complexity: O(1)
//9)average():
//Time Complexity: O(n)
//Space Complexity: O(1)
//10)reverse():
//Time Complexity: O(n), 
//Space Complexity: O(1)
//11)detectLoop():
//Time Complexity: O(n)
//Space Complexity: O(1)
//===========================Completed time and space complexity from all functions======================//
