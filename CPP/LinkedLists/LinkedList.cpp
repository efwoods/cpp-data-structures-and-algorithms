#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
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

        // Destructor
        ~LinkedList() {
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        // Append
        void append(int value){
            Node* newNode = new Node(value);
            if(tail){
                tail->next = newNode;
                tail = newNode;
            } else {
                head = newNode;
                tail = newNode;
            }
            length++;
        }

        void printList() {
            Node* temp = head;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            cout << "Head: " << head->value << endl;
        }

        void getTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void getLength(){
            cout << "Length: " << length << endl;
        }
};

int main(){
    // LinkedList* myLinkedList = new LinkedList(4);
    // myLinkedList->getHead();
    // myLinkedList->getTail();
    // myLinkedList->getLength();

    // myLinkedList->printList();

    // Testing Append
    LinkedList* myAppendedList = new LinkedList(1);
    myAppendedList->printList();

    myAppendedList->append(2);
    myAppendedList->printList();
}