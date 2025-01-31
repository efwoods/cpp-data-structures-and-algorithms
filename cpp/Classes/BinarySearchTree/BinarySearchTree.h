#pragma once

class Node{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree{
    public:
        Node* root;
    
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool insert(int value);
        bool contains(int value);
        void destroy(Node* currentNode);
};