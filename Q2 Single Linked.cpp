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

class List {

private:
	Node* headPtr;

public:
	List() {
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


	void insert(int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		while (currentNodePtr != 0) {
			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(0);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}

	void insertAtIndex(int insertIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		int index = 0;

		while (currentNodePtr != 0) {

			if (index == insertIndex)
				break;

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
			index++;
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(currentNodePtr);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}


	int read(int readIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == readIndex)
				return currentNodePtr->getData();

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;

		}

		return -1; // an invalid value indicating 
					// index is out of range

	}

	void modifyElement(int modifyIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == modifyIndex) {
				currentNodePtr->setData(data);
				return;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}


	}


	void deleteElement(int deleteIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		Node* nextNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == deleteIndex) {
				nextNodePtr = currentNodePtr->getNextNodePtr();
				break;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}

		prevNodePtr->setNextNodePtr(nextNodePtr);

	}


	void IterativePrint() {

		Node* currentNodePtr = headPtr->getNextNodePtr();

		while (currentNodePtr != 0) {
			cout << currentNodePtr->getData() << " ";
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		cout << endl;

	}

	int Length() { //added this function for the for loops for selection sort // I like for loops more than while loops

		Node* currentNodePtr = headPtr->getNextNodePtr();
		int length = 0;

		while (currentNodePtr != 0) {
			currentNodePtr = currentNodePtr->getNextNodePtr();
			length++;
		}

		return length;

	}


};



Node* findMinimumDataNodeAddress(List list, Node* currentNodePtr) {

	Node* minDataNodePtr = currentNodePtr; // minIndex equiv. minDataNodePtr
	currentNodePtr = currentNodePtr->getNextNodePtr(); // currentNodePtr equiv. index j

	while (currentNodePtr != 0) {

		if (minDataNodePtr->getData() > currentNodePtr->getData())
			minDataNodePtr = currentNodePtr;
		
		currentNodePtr = currentNodePtr->getNextNodePtr();

	}

	return minDataNodePtr;


}



void SelectionSort(List list) {

	int listLength = list.Length();

	Node* currentNodePtr = list.getHeadPtr();
	Node* minDataNodePtr;
	int minholder;
	int currentholder;


	for (int a = 0; a < listLength; a++) {
		currentNodePtr = currentNodePtr->getNextNodePtr();
		minDataNodePtr = findMinimumDataNodeAddress(list, currentNodePtr);
		minholder = minDataNodePtr->getData();
		currentholder = currentNodePtr->getData();
		currentNodePtr->setData(minholder);
		minDataNodePtr->setData(currentholder);
		
		
	}

	// Implement the selection sort algorithm here...

	// Run a loop using currentNodePtr
		// for each iteration of this loop
			// call the findMinimumDataNodeAddress function to find the address of the node with the minimum data
			// starting from the current node.

		// swap the data at currentNode with the node that has the minimum data found using the findMinimumDataNodeAddress function


}



int main() {

	using namespace std::chrono;

	srand(time(NULL));


	int maxValue;
	cout << "Enter the max value: ";
	cin >> maxValue;

	int numTrials;
	cout << "Enter the number of trials: ";
	cin >> numTrials;


	for (int listSize = 1000; listSize <= 20000; listSize += 1000) {

		double totalSortingTime = 0;

		for (int trials = 1; trials <= numTrials; trials++) {

			List integerList; // Create an empty list

			for (int i = 0; i < listSize; i++) {

				int value = 1 + rand() % maxValue;
				integerList.insertAtIndex(i, value);
			}




			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			SelectionSort(integerList);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			duration<double, std::milli> sortingTime_milli = t2 - t1;
			totalSortingTime += sortingTime_milli.count();


		}


		cout << "Average sorting time for list size " << listSize << " is " << (totalSortingTime / numTrials) << " milli seconds " << endl;

	}// list size loop

	system("pause");

	return 0;
}