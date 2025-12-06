#include "DoublyLinkedList.h"
#include <iostream>
#include <string>
#include <sstream> 
template<typename T>

class Node
{

public:
    T data;

    Node<T>* next;

    Node() : data(), next(nullptr) {};

    Node(T value, Node<T>* nextNode = nullptr) {
        data = value;
        next = nextNode;
    };

    

};


template<typename T>
class LinkedList
    
{
//moved private to top of the class
private:

    Node<T>* head;

    Node<T>* tail;

public:

    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor (Added for memory management)
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    Node<T>* getHead() const { return head; }
          // return the head pointer

    Node<T>* getTail() const { return tail; };  // returns the tail pointer

    void ListAppend(T value) { // inserts an element at the end of the list
        
        //Create the new node
        Node<T>* newNode = new Node<T>(value); 

        //If the list is empty, new node is both head and tail
        if (head == nullptr) {
            
            head = newNode;
            tail = newNode;
        }
        else {
            //If the list is NOT empty, link the current tail to the new node
            tail->next = newNode;
            //Update tail to point to the new node
            tail = newNode;
        }
    }

    void listPrepend(T value) {//inserts a n element at the head of the list

        // Create the new node. Initialized with the given value.
        Node<T>* newNode = new Node<T>(value);

        //  Point the new node's 'next' pointer to the current head.
        newNode->next = head;

        //  Update the list's head to point to the new node.
        head = newNode;

        // Special Case: If the list was empty, the new node is also the tail.
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Insert value after the curNode
    void insertAfter(Node<T>* curNode, T value) {
        // If curNode is nullptr, we can't insert "after" it. 
        if (curNode == nullptr) {
            std::cout << "Cannot insert after a nullptr node." << std::endl;
            return;
        }

        // Create the new node, linking it to curNode's current next node.
        Node<T>* newNode = new Node<T>(value, curNode->next);

        // Link curNode to the new node.
        curNode->next = newNode;

        // Special Case: If curNode was the tail, the new node is the new tail.
        if (curNode == tail) {
            tail = newNode;
        }
    }

    // Remove Node after CurNode
    void removeAfter(Node<T>* curNode) {
        
        // Nothing to remove after curNode or list is empty
        if (curNode == nullptr || curNode->next == nullptr) {
            return;
        }
        // Node to be deleted

        Node<T>* nodeToRemove = curNode->next; 
        // Link curNode to the node *after* nodeToRemove
        curNode->next = nodeToRemove->next;    

        // Special Case: If the removed node was the tail, update tail to curNode.
        if (nodeToRemove == tail) {
            tail = curNode;
        }

        // Delete the node.
        delete nodeToRemove;
    }

    // Removes the first element
    void removeHead() {
        
        // List is empty
        if (head == nullptr) {
            return;
        }
        // Save the current head
        Node<T>* nodeToRemove = head;      
        
        // Move head pointer to the next node
        head = head->next;                

        // Special Case: If the list is now empty (removed the only element), update tail.
        if (head == nullptr) {
            tail = nullptr;
        }

        // Delete the original head.
        delete nodeToRemove;
    }

    // Removes the last element
    void removeTail() {
        // List is empty
        if (head == nullptr) {
            return;
        }
        // Only one element in the list
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        // Traverse the list to find the node before the tail.
        Node<T>* curNode = head;
        while (curNode->next != tail) {
            curNode = curNode->next;
        }

        //Delete the current tail.
        delete tail;

        //Update the tail pointer and break the link.
        tail = curNode;
        tail->next = nullptr;
    }

    // Print the elements of the linked list
    void printList() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << std::endl;

    }

    // Return the number of elements in the linked list
    int getLength() {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Search for an element and return the pointer to the node
    Node<T>* search(T element) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == element) {
                return current; // Found the element!
            }
            current = current->next;
        }
        return nullptr; // Element not found
    }
};


int main()
{

    DoublyLinkedList<std::string> strList;

    //Test Double
    strList.append("V");
    strList.append("i");
    strList.append("nc");
    strList.append("ent");
    strList.prepend("My Name is: ");
    strList.printList();

    return 0;

}

