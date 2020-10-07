#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>//clock_t, clock, CLOCKS_PER_SEC

#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;

// implementing a doubly linked list


class Node {

private:
	int data;
	Node* nextNodePtr;
	Node* prevNodePtr;

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

	void setPrevNodePtr(Node* nodePtr) {
		prevNodePtr = nodePtr;
	}

	Node* getPrevNodePtr() {
		return prevNodePtr;
	}

};

class Stack {

private:
	Node* headPtr;
	Node* tailPtr;


public:
	Stack() {
		headPtr = new Node();
		tailPtr = new Node();
		headPtr->setNextNodePtr(0);
		tailPtr->setPrevNodePtr(0);
	}

	Node* getHeadPtr() {
		return headPtr;
	}

	Node* getTailPtr() {
		return tailPtr;
	}

	bool isEmpty() {

		if (headPtr->getNextNodePtr() == 0)
			return true;

		return false;
	}


	void push(int data) {

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(0);

		Node* lastNodePtr = tailPtr->getPrevNodePtr();

		if (lastNodePtr == 0) {

			headPtr->setNextNodePtr(newNodePtr);
			newNodePtr->setPrevNodePtr(0);

		}
		else {

			lastNodePtr->setNextNodePtr(newNodePtr);
			newNodePtr->setPrevNodePtr(lastNodePtr);

		}

		tailPtr->setPrevNodePtr(newNodePtr);

	}


	int pop() {

		Node* lastNodePtr = tailPtr->getPrevNodePtr();
		Node* prevNodePtr = 0;

		int poppedData = -100000; //empty stack

		if (lastNodePtr != 0) {
			prevNodePtr = lastNodePtr->getPrevNodePtr();
			poppedData = lastNodePtr->getData();
		}
		else
			return poppedData;

		if (prevNodePtr != 0) {
			prevNodePtr->setNextNodePtr(0);
			tailPtr->setPrevNodePtr(prevNodePtr);
			delete lastNodePtr;
		}
		else {
			headPtr->setNextNodePtr(0);
			tailPtr->setPrevNodePtr(0);
		}

		return poppedData;

	}


	int peek() {

		Node* lastNodePtr = tailPtr->getPrevNodePtr();

		if (lastNodePtr != 0)
			return lastNodePtr->getData();
		else
			return -100000; //  empty stack

	}


	void IterativePrint() {

		Node* currentNodePtr = headPtr->getNextNodePtr();

		while (currentNodePtr != 0) {
			cout << currentNodePtr->getData() << " ";
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		cout << endl;

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



	//cout << "Integers pushed to the Stack: ";

	using namespace std::chrono;

	double totalPushingTime = 0;
	double totalPoppingTime = 0;


	for (int trials = 1; trials <= numTrials; trials++) {

		Stack integerStack; // Create an empty stack

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < StackSize; i++) {
			int value = 1 + rand() % maxValue;
			//cout << value << " ";
			integerStack.push(value);
		}

		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double, std::micro> pushingTime_micro = t2 - t1;
		totalPushingTime += pushingTime_micro.count();

		//cout << endl;

		//cout << "Contents of the Stack: ";
		//integerStack.PrintToptoBottom();

		// to read an element at a particular index (before delete)

		//cout << "Popping out elements from the stack: ";

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