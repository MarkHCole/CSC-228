#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <time.h>
#include <stdlib.h>

using namespace std;

// implementing the dynamic List ADT using Linked List

class Node {

private:
	int data;
	Node* nextNodePtr;

public:
	Node() {}

	void setData(int d) {
		data = d;
	}

	int getData() {
		return data;
	}

	void setNextNodePtr(Node* nodePtr) {
		nextNodePtr = nodePtr;
	}

	Node* getNextNodePtr() {
		return nextNodePtr;
	}

};

class Stack {

private:
	Node* headPtr;

public:
	Stack() {
		headPtr = new Node();
		headPtr->setNextNodePtr(0);
	}

	Node* getHeadPtr() {
		return headPtr;
	}

	bool isEmpty() {

		if (headPtr->getNextNodePtr() == 0)
			return true;

		return false;
	}



	void push(int data) {

		Node* nextnodeptr = headPtr;
		Node* newnode = new Node();
		if (nextnodeptr->getNextNodePtr() == 0) {
			newnode->setData(data);
			headPtr->setNextNodePtr(newnode);
		}
		else {
			nextnodeptr = nextnodeptr->getNextNodePtr();
			newnode->setData(data);
			newnode->setNextNodePtr(nextnodeptr);
			headPtr->setNextNodePtr(newnode);
		}
		//cout << data << " ";

	}


	int peek() {

		Node* nextnodeptr = headPtr;
		if (nextnodeptr->getNextNodePtr() == 0) {
			cout << "Stack is empty" << endl;
			return 0;
		}
		nextnodeptr = headPtr->getNextNodePtr();
		return nextnodeptr->getData();

	}


	int pop() {

		if (headPtr->getNextNodePtr()->getData() == NULL) {
			headPtr->setNextNodePtr(0);
			return 0;
		}
		else {
			Node* currentnodeptr = headPtr->getNextNodePtr();
			Node* nextnodeptr = currentnodeptr->getNextNodePtr();
			//cout << currentnodeptr->getData() << " ";
			delete currentnodeptr;
			headPtr->setNextNodePtr(nextnodeptr);
			return 0;
		}


	}



};






int main() {

	int StackSize;
	cout << "Enter the number of elements you want to push: ";
	cin >> StackSize;

	int maxValue;
	cout << "Enter the max. value: ";
	cin >> maxValue;

	int numTrials;
	cout << "Enter the number of trials: ";
	cin >> numTrials;


	srand(time(NULL));


	using namespace std::chrono;

	double totalPushingTime = 0;
	double totalPoppingTime = 0;


	for (int trials = 1; trials <= numTrials; trials++) {

		Stack integerStack; // Create an empty stack

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < StackSize; i++) {
			int value = 1 + rand() % maxValue;
			integerStack.push(value);
		}

		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double, std::micro> pushingTime_micro = t2 - t1;
		totalPushingTime += pushingTime_micro.count();



		t1 = high_resolution_clock::now();
		while (!integerStack.isEmpty())
			integerStack.pop();

		t2 = high_resolution_clock::now();
		duration<double, std::micro> poppingTime_micro = t2 - t1;
		totalPoppingTime += poppingTime_micro.count();

	}// trials

	cout << "Avg. Pushing time (microseconds): " << (totalPushingTime / numTrials) << endl;
	cout << "Avg. Popping time (microseconds): " << (totalPoppingTime / numTrials) << endl;

	system("pause");

	//cout << endl;


	return 0;
}