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
        bool rContains(Node* currentNode, int value);
        bool rContains(int value);
        Node* rInsert(Node* currentNode, int value);
        void rInsert(int value);
        Node* deleteNode(Node* currentNode, int value);
        void deleteNode(int value);
        int minValue(Node* currentNode);
        Node* getRoot();
        void BFS();
        void DFSPreOrder(Node* currentNode);
        void DFSPreOrder();
        void DFSPostOrder(Node* currentNode);
        void DFSPostOrder();
        void DFSInOrder(Node* currentNode);
        void DFSInOrder();
};

