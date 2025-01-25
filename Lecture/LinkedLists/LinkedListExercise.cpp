/*
LL: Constructor

Write the constructor for the LinkedList class that initializes a singly linked list with a single node containing an integer value.

The LinkedList constructor takes an integer value as a parameter and performs the following tasks:

    Create a new Node object with the given value and store its address in a Node* newNode pointer.

    Set the head pointer to the address of the new node.

    Set the tail pointer to the address of the new node.

    Set the length to 1.

*/

#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Write the LinkedList constructor                   |
        //   | - Constructor takes an int value                     |
        //   | - Create a new node                                  |
        //   | - Initialize head, tail to the new node              |
        //   | - Length starts at 1                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use 'new' to allocate memory for the new node      |
        //   | - Make sure to set head and tail pointers            |
        //   | - Make sure to set length                            |
        //   | - Check output from Test.cpp in "User logs"          |
        //   +======================================================+


        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

};