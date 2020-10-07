#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <ctime>
#include <ratio>
#include <chrono>


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

class SortedList {

private:
	Node* headPtr;

public:
	SortedList() {
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



	void insertSortedOrder(int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		
		while (currentNodePtr != 0) {
			if (data < currentNodePtr->getData()) {
				Node* newNodePtr = new Node();
				newNodePtr->setData(data);
				newNodePtr->setNextNodePtr(currentNodePtr);
				prevNodePtr->setNextNodePtr(newNodePtr);
				return;
			}
			currentNodePtr = currentNodePtr->getNextNodePtr();
			prevNodePtr = prevNodePtr->getNextNodePtr();
		} 
		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(NULL);
		prevNodePtr->setNextNodePtr(newNodePtr);
		return;
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

	using namespace std::chrono;

	int listSize;
	cout << "Enter the number of elements you want to insert: ";
	cin >> listSize;

	int maxValue;
	cout << "Enter the maximum value for an element in the list: ";
	cin >> maxValue;

	srand(time(NULL));

	SortedList integerList; // Create an empty list

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < listSize; i++) {
		int value = 1 + rand() % maxValue;
		integerList.insertSortedOrder(value);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double, std::nano> insertionTime_nano = t2 - t1;

	//integerList.IterativePrint();//troubleshooting
	cout << "Avg insertion time per element " << (insertionTime_nano.count() / listSize) << endl;


	system("pause");

	return 0;
}