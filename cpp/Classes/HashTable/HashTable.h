#pragma once
#include <string>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;
        Node(string key, int value){
            this->key = key;
            this->value = value;
        }
};

class HashTable{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        ~HashTable();
        void printTable();
        int hash(string key);
        void set(string key, int value);
        int get(string key);
};