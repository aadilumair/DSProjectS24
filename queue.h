#pragma once

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(T nData) {
		next = nullptr;
		data = nData;
	}
};

template<typename T1>
class Queue
{
private:
	Node<T1> * Rear;
	int counter;
public:
	Node<T1>* Front;

	Queue() {
		counter = 0;
		Front = nullptr;
		Rear = nullptr;
	}

	bool enqueue(T1 data) {
		if (Rear == nullptr) {
			Rear = new Node<T1>(data);
			Front = Rear;
			counter++;
			return true;
		}

		Node<T1> * temp = new Node<T1>(data);
		Rear->next = temp;
		Rear = temp;
	}

	bool dequeue() {
		if (Front == nullptr)
			return false;

		if (Front == Rear) {
			Rear = nullptr;
			delete Front;
			Front = nullptr;
			counter--;
			return true;
		}
		
		Node<T1>* temp = Front;
		Front = Front->next;
		delete temp;
		counter--;
		return true;
	}

	T1 & peek() {
		return Front->data;
	}

	int getSize() {
		return counter;
	}

	void clear() {
		while (Front != nullptr) {
			dequeue();
		}
	}

	~Queue() {
		clear();
	}

};