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

        // Delete Last
        void deleteLast(){
            if(length > 1){
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
                length--;
            } else if (length == 1) {
                delete tail;
                head = nullptr;
                tail = nullptr;
                length = 0;
            } else {
                return;
            }
        }

        // Prepend
        void prepend(int value){
            Node* newNode = new Node(value);
            if(head){
                newNode->next = head;
                head = newNode;
                length++;
            }
            else {
                head = newNode;
                tail = newNode;
                length = 1;
            }
        }

        // Delete First
        void deleteFirst(){
            Node* temp = head;
            if (length > 1){
                head = head->next;
                delete temp;
                length--;
            } else if (length == 1){
                delete tail;
                head = nullptr;
                tail = nullptr;
                length = 0;
            } else {
                return;
            }
        }

        // Get
        Node* get(int index){
            if (index == 0){
                return head;
            } else if (index >= length) {
                return nullptr;
            } else {
                Node *temp = head;
                int i = 0;
                while(i < index){
                    temp = temp->next;
                    i++;
                }
                return temp;
                }
            }

        // Set
        void set(int index, int value){
            if (index == 0){
                head->value = value;
            } else if (index >= length) {
                return;
            } else {
                Node *temp = head;
                int i = 0;
                while (i < index){
                    temp = temp->next;
                    i++;
                }
                temp->value = value;
            }
        }

        // Insert
        void insert(int index, int value){
            if (length == 0){
                Node* newNode = new Node(value);
                head = newNode;
                tail = newNode;
                length = 1;
            } else if (index >= length) {
                append(value);
            } else if (index <= 0) {
                prepend(value);
            } else {
                int i = 0;
                Node* pre = head;
                Node* post = head;
                while (i < index){
                    pre = post;
                    post = post->next;
                    i++;
                }
                pre->next = new Node(value);
                pre->next->next = post;
                length++;
            }
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
    // LinkedList* myAppendedList = new LinkedList(1);
    // myAppendedList->printList();

    // myAppendedList->append(2);
    // myAppendedList->printList();

    // Testing DeleteLast
    // LinkedList* myList = new LinkedList(1);
    // myList->append(2);
    // myList->printList();

    // cout << '\n';

    // myList->deleteLast();
    // myList->printList();
    
    // myList->deleteLast();
    // myList->printList();

    // myList->deleteLast();
    // myList->printList();

    // Testing Prepend:
    // LinkedList* myList = new LinkedList(2);
    // myList->printList();

    // myList->prepend(1);
    // myList->printList();

    // myList->deleteLast();
    // myList->deleteLast();
    // myList->printList();

    // myList->prepend(1);
    // myList->printList();

    // Testing Delete First
    // LinkedList* myList = new LinkedList(1);
    // myList->append(2);
    // myList->printList();

    // cout << "\n";

    // // Delete 1
    // myList->deleteFirst();
    // myList->printList();

    // cout << "\n";

    // // Delete 2
    // myList->deleteFirst();
    // myList->printList();

    // cout << "\n";

    // // Does not delete
    // myList->deleteFirst();
    // myList->printList();

    // Testing Insert
    LinkedList* myList = new LinkedList(1);
    myList->deleteFirst();
    myList->printList();

    cout << "Empty List." << "\n\n";

    myList->insert(0,1); // insert into empty LinkedList
    myList->printList();

    cout << "\n";

    myList->insert(2, 2); // insert at end of list
    myList->printList();

    cout << "\n";

    myList->insert(0, 0); // insert at beginning of list
    myList->printList();

    cout << "\n";

    myList->insert(1, 3); // insert after index == 1; values: 0, 3, 1, 2
    myList->printList();
}