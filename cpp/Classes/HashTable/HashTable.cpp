#include "HashTable.h"
#include <iostream>

using namespace std;

void HashTable::printTable(){
    for(int i = 0; i < SIZE; i++){
        cout << i << ":" << endl;
        if(dataMap[i]) {
            Node* temp = dataMap[i];
            while(temp) {
                cout << " {" << temp->key << ", " << temp->value << "}" << endl;
                temp = temp->next;
            }
        }
    }
}