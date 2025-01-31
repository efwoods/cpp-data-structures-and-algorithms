#include "HashTable.h"
#include <iostream>
#include <string>

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

int HashTable::hash(string key){
    int hash = 0;
    for(int i = 0; i < key.length(); i++){
        int asciiValue = int (key[i]);
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}