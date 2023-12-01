#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    void deleteFirst() {
        if (!head) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* secondLast = head;
        while (secondLast->next->next) {
            secondLast = secondLast->next;
        }
        delete secondLast->next;
        secondLast->next = nullptr;
    }

    void insertAt(int value, int index) {
        if (index == 0) {
            addFirst(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!current) {
                return;
            }
            current = current->next;
        }
        if (!current) {
            return;
        }
        newNode->next = current->next;
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

    bool isPalindrome() {
        // Implement this method to check if the linked list is a palindrome
        // You may use a stack or reverse the second half and compare
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
        // Implement this method to find the maximum value in the linked list
        // Assume non-empty list for simplicity
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
        // Implement this method to find the average value of the linked list
        // Assume non-empty list for simplicity
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
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
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
    LinkedList linkedList;

    // Adding elements to the linked list
    linkedList.addLast(1);
    linkedList.addLast(2);
    linkedList.addLast(3);
    linkedList.addLast(2);
    linkedList.addLast(1);
    std::cout << "Original Linked List:" << std::endl;
Node*current = linkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    linkedList.addFirst(0);
    linkedList.deleteLast();
    linkedList.insertAt(6, 3);

    std::cout << "Modified Linked List:" << std::endl;
    current = linkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Search 3: " << (linkedList.search(3) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 8: " << (linkedList.search(8) ? "Found" : "Not Found") << std::endl;

    std::cout << "Is Palindrome: " << (linkedList.isPalindrome() ? "Yes" : "No") << std::endl;

    std::cout << "Count Nodes: " << linkedList.countNodes() << std::endl;

    std::cout << "Max Value: " << linkedList.max() << std::endl;

    std::cout << "Average Value: " << linkedList.average() << std::endl;

    linkedList.reverse();
    std::cout << "Reversed Linked List:" << std::endl;
    current = linkedList.head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Detect Loop: " << (linkedList.detectLoop() ? "Yes" : "No") << std::endl;

    return 0;
}


// =============================TIME AND SPACE COMPLEXITY OF ALL FUNCTIONS:================================//
//1)Linkedlist constructor:
//Time Complexity:O(1)
//Space Complexity:O(1)
//2)Add First:
//Time Complexity:O(1)
//Space Complexity:O(1)
//3)Add Last:
//Time Complexity:O(n)
//Space Complexity:O(10
//4)Delete First:
//Time Complexity:O(1)
//Space Complexity:O(1)
//5)Delete Last:
//Time Complexity:O(n)
//Space Complexity:O(1)
//6)insert At:
//Time Complexity:O(n)
//Space Complexity:O(1)
//7)Search:
//Time Complexity:O(n)
//Space Complexity:O(1)
//8)is Palindrome:
//Time Complexity:O(n)
//Space Complexity:O(n)
//9)count Nodes:
//Time Copmlexity:O(n)
//Space Complexity:O(1)
//10)max():
//Time Complexity:O(n)
//Space Complexity:O(1)
//11)Average:
//Time Copmlexity:O(n)
//Space Complexity:O(1)
//12)Delete Loop:
//Time Complexity:O(n)
//Space Complexity:O(1)
//=============================Completed all functions time and space complexity===============================//
