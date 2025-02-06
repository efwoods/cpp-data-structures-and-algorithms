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

Node* BinarySearchTree::deleteNode(Node* currentNode, int value){
    if(currentNode == nullptr){
        return nullptr;
    }
    if(value < currentNode->value){
        currentNode->left = deleteNode(currentNode->left, value);
    } else if(value > currentNode->value){
        currentNode->right = deleteNode(currentNode->right, value);
    } else {
        // delete current node with no leafs
        if(currentNode->left == nullptr && currentNode->right == nullptr){
            delete(currentNode);
            return nullptr;
        } else if(currentNode->left == nullptr){
            // delete current node with left leaf
            Node* temp = currentNode->right;
            delete(currentNode);
            return temp;
        } else if (currentNode->right == nullptr){
            // delete current node with right leaf  
            Node* temp = currentNode->left;
            delete(currentNode);
            return temp;
        } else {
            // delete current node with both leafs
            int minimumValue = minValue(currentNode->right);
            currentNode->value = minimumValue;
            currentNode->right = deleteNode(currentNode->right, minimumValue);
        }
    }

    return currentNode;

}

void BinarySearchTree::deleteNode(int value){
    root = deleteNode(root, value);
}

int BinarySearchTree::minValue(Node* currentNode){
    while (currentNode->left != nullptr){
        currentNode = currentNode->left;
    }
    return currentNode->value;
}

Node* BinarySearchTree::getRoot(){
    return root;
}