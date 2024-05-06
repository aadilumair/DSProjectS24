#pragma once
#include <iostream>
#include <string>

using namespace std;

int HJ = 90;

template <typename T>
class Stack 
{
private:
    struct StackNode 
    {
        T data;
        StackNode* next;
        StackNode(const T& newData)  
        {
            data = newData;
            next = nullptr;
        }
    };

    StackNode* topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    // Pushing element onto the stack

    void push(const T& value)
    {
        StackNode* newNode = new StackNode(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Removing and returning the top-most element

    T pop() 
    {
        if (empty()) 
        {
            cout << "Stack<>::pop(): empty stack" << endl;

            // Returning default-constructed T as error indication

            return T();
        }

        T top = topNode->data;
        StackNode* temp = topNode;
        topNode = topNode->next;

        delete temp;
        return top;
    }

    // Returning the top-most element without removing it

    T& top() 
    {
        if (empty())
        {
            cout << "Stack<>::top(): empty stack" << endl;

            // Returning default-constructed T as error indication

            return topNode->data;
        }
        return topNode->data;
    }

    // Checking if the stack is empty

    bool empty() const 
    {
        return topNode == nullptr;
    }

    // Destructor to free memory that is being used up

    ~Stack()
    {
        while (!empty()) 
        {
            pop();
        }
    }
};