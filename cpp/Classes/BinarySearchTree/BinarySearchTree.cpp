#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}
BinarySearchTree::~BinarySearchTree(){
    destroy(root);
}

bool BinarySearchTree::insert(int value){
    Node* newNode = new Node(value);
    if (root == nullptr){
        root = newNode;
        return true;
    }
    Node* temp = root;
    while(true){
        if (newNode->value == temp->value){ // node being inserted is already in the tree;
            return false;
        }
        if (newNode->value < temp->value) {
            if(temp->left == nullptr){
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        } else {
            if(temp->right == nullptr){
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::contains(int value){
    Node* temp = root;
    while(temp != nullptr){
        if(temp->value == value){
            return true;
        }
        if(value < temp->value){ // search left
            temp = temp->left;
        } else { // search right
            temp = temp->right;
        }
    }
    return false;
}

void BinarySearchTree::destroy(Node* currentNode){
    if (currentNode == nullptr){
        return;
    }
    if (currentNode->left) {
        destroy(currentNode->left);
    }
    if (currentNode->right){
        destroy(currentNode->right);
    }
    delete currentNode;
}

bool BinarySearchTree::rContains(Node* currentNode, int value){
    if (currentNode == nullptr) return false;

    if (currentNode->value == value) return true;

    if (value < currentNode->value) {
        return rContains(currentNode->left, value);
    } else {
        return rContains(currentNode->right, value);
    }
}

bool BinarySearchTree::rContains(int value){
    return rContains(root, value);
}