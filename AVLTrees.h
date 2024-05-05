//
// Created by Salman Umar on 4/28/24.
//

#ifndef PROJECTS24_AVLTREES_H
#define PROJECTS24_AVLTREES_H

//code for AVLTrees
#include <iostream>
#include <algorithm>
#include "func.h"
#include <queue>
#include "Stack.h"
using namespace std;

template <typename T>
class AVLNode {
public:
    T key;
    AVLNode<T> *left;
    AVLNode<T> *right;
    int height;

    AVLNode(T key){
        this->key = key;
        this->left = this->right = NULL;
        this->height = 1;
    }
};

template <typename T>
class AVLTree {
public:
    AVLNode<T> *Root;
    int count;

    T& operator[](int index) {
        int currentIndex = 0;
        return atIndex(index);
    }
    // Utility function to calculate the size of the tree
    int size(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return 1 + size(node->left) + size(node->right);
    }

   

    T& atIndex(int index) {
        if (Root == nullptr || index < 0)
            throw out_of_range("Index out of range");

        Stack<AVLNode<T>*> stack;
        AVLNode<T>* current = Root;
        int currentIndex = 0;

        while (!stack.empty() || current != nullptr) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();

            if (currentIndex == index)
                return current->key;

            currentIndex++;
            current = current->right;
        }

        throw out_of_range("Index out of range");
    }

    int height(AVLNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(AVLNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode<T> *node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    AVLNode<T>* rightRotate(AVLNode<T> *y) {
        AVLNode<T> *x = y->left;
        AVLNode<T> *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode<T>* leftRotate(AVLNode<T> *x) {
        AVLNode<T> *y = x->right;
        AVLNode<T> *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode<T>* _insert(AVLNode<T> *node, T key) {
        if (node == nullptr)
            return new AVLNode<T>(key);

        if (key <= node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else
            return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case (LL)
        if (balance > 1 && key <= node->left->key)
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

    AVLNode<T>* minValueNode(AVLNode<T> *node) {
        AVLNode<T> *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode<T>* _delete(AVLNode<T> *root, T key) {
        if (root == nullptr)
            return root;

        if (key <= root->key)
            root->left = _delete(root->left, key);
        else if (key > root->key)
            root->right = _delete(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode<T> *temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                AVLNode<T> *temp = minValueNode(root->right);

                root->key = temp->key;

                root->right = _delete(root->right, temp->key);
            }
        }

        if (root == nullptr)
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

    AVLNode<T>* _search(AVLNode<T> *node, T key) {
        if (node == nullptr || node->key == key)
            return node;

        if (node->key <= key)
            return _search(node->right, key);

        return _search(node->left, key);
    }

    void _inorder(AVLNode<T> *node) {
        if (node != nullptr) {
            _inorder(node->left);
            node->key.out();
            _inorder(node->right);
        }
    }

public:
    AVLTree() : Root(nullptr) {
        count = 0;
    }

    void insert(T key) {
        Root = _insert(Root, key);
        count++;
    }

    void remove(T key) {
        Root = _delete(Root, key);
        if (Root == nullptr)
            count = 0;
        else
            count--;
    }

    bool search(T key) {
        return _search(Root, key) != nullptr;
    }

    void inorder() {
        _inorder(Root);
        cout << endl;
    }
};


#endif //PROJECTS24_AVLTREES_H
