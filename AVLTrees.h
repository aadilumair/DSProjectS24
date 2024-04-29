//
// Created by Salman Umar on 4/28/24.
//

#ifndef PROJECTS24_AVLTREES_H
#define PROJECTS24_AVLTREES_H

//code for AVLTrees
#include <iostream>
using namespace std;

class AVLNode {
public:
    int key;
    AVLNode * left;
    AVLNode * right;
    int height;

    AVLNode(int key){
        this->key = key;
        this->left = this->right = NULL;
        this->height = 1;
    }
};

class AVLTree {
public:
    AVLNode * Root;

    int height(AVLNode * node) {
        if (node == NULL){
            return 0;
        }
        return node->height;
    }

    int balanceFactor(AVLNode * node) {
        if (node == NULL){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode * node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    AVLNode* rightRotate(AVLNode * y) {
        AVLNode * x = y->left;
        AVLNode * T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode * x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* _insert(AVLNode *node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else
            return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case (LL)
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case (RR)
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case (LR)
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case (RL)
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode *node) {
        AVLNode *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    AVLNode* _delete(AVLNode *root, int key) {
        if (root == NULL)
            return root;

        if (key < root->key)
            root->left = _delete(root->left, key);
        else if (key > root->key)
            root->right = _delete(root->right, key);
        else {
            if (root->left == NULL || root->right == NULL) {
                AVLNode *temp = root->left ? root->left : root->right;

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                AVLNode *temp = minValueNode(root->right);

                root->key = temp->key;

                root->right = _delete(root->right, temp->key);
            }
        }

        if (root == NULL)
            return root;

        updateHeight(root);

        int balance = balanceFactor(root);

        // Left Left Case (LL)
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case (LR)
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case (RR)
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case (RL)
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode* _search(AVLNode *node, int key) {
        if (node == NULL || node->key == key)
            return node;

        if (node->key < key)
            return _search(node->right, key);

        return _search(node->left, key);
    }

    void _inorder(AVLNode *node) {
        if (node != NULL) {
            _inorder(node->left);
            cout << node->key << " ";
            _inorder(node->right);
        }
    }

public:
    AVLTree(){
        Root = NULL;
    }

    void insert(int key) {
        Root = _insert(Root, key);
    }

    void remove(int key) {
        Root = _delete(Root, key);
    }

    bool search(int key) {
        return _search(Root, key) != NULL;
    }

    void inorder() {
        _inorder(Root);
        cout << endl;
    }
};

#endif //PROJECTS24_AVLTREES_H
