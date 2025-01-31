#pragma once
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;

        Node(string key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
        int hash(string key);
        FRIEND_TEST(HashTableTest, Hash); // allows testing of private members;

    public:
        ~HashTable();
        void printTable();
        void set(string key, int value);
        int get(string key);
        vector<string> keys();
};