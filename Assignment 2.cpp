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


	void IterativePrint(int size) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		int i = 0;
		while (currentNodePtr != 0) {
			cout << "Node " << i << ": ";
			cout << currentNodePtr->getData() << " ";
			if (i == size - 1) {
				cout << endl << "Appended Values:" << endl;
			}
			i++;
			currentNodePtr = currentNodePtr->getNextNodePtr();

		}

		cout << endl;

	}



	void mergeList(List secondList) {
		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		Node* secondListHeadPtr = secondList.getHeadPtr();
		Node* secondListCurrentNodePtr = secondListHeadPtr->getNextNodePtr();
		int currentListValue;
		int secondListValue;
		//int h = 1; //loop debugging
		//int i; //loop debugging
		bool append = true;
		while (secondListCurrentNodePtr != 0) {
			
			secondListValue = secondListCurrentNodePtr->getData();
			
			//i = 1; //loop debugging
			while  (currentNodePtr != 0) {  //Will iterate through entire list to ensure once unique values aren't added again

				

				currentListValue = currentNodePtr->getData();
				

				if (secondListValue == currentListValue) {
					//cout << "First list already contains " << secondListValue << endl;  // debugging
					append = false;
					break;
				}

				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();
				//cout << "Comparing value of List 1 Node " << h << " against value of List 2 Node ";// debugging
				//cout << i << endl;// loop debugging
				//i++;
			}
			
			if (append == true) {
				insert(secondListValue);
			}

			append = true;

			secondListCurrentNodePtr = secondListCurrentNodePtr->getNextNodePtr();
			currentNodePtr = headPtr->getNextNodePtr();
			prevNodePtr = headPtr;
			//h++;
			//cout << "h" << endl;// loop debugging - helped catch an infinite loop
			
		}


	}

};

int main() {

	int maxValue;
	cout << "Enter the maximum value in both the lists: ";
	cin >> maxValue;

	int listSize;
	cout << "Enter the size for both the lists: ";
	cin >> listSize;


	srand(time(NULL));

	using namespace std::chrono;


	List firstIntegerList;

	for (int i = 0; i < listSize; i++) {
		int value = 1 + rand() % maxValue;
		firstIntegerList.insertAtIndex(i, value);
		//if (i % 1000 == 0 || i == listSize-1) {
		//	cout << "Created node " << i << endl;
		//}

		//cout << "a: " << value << endl;// loop debugging - thought it was hung up, but it was just taking a while
	}



	List secondIntegerList;

	for (int i = 0; i < listSize; i++) {
		int value = 1 + rand() % maxValue;
		secondIntegerList.insertAtIndex(i, value);
		//if (i % 1000 == 0 || i == listSize - 1) {
		//	cout << "Created node " << i << endl;
		//}

		//cout << "b: " << i << endl;// loop debugging - thought it was hung up, but it was just taking a while
	}


	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	firstIntegerList.mergeList(secondIntegerList);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double, std::milli> mergingTime_milli = t2 - t1;
	double mergingTime = mergingTime_milli.count();

	//firstIntegerList.IterativePrint(listSize);// debugging

	cout << "\n Merging Time (milliseconds): " << (mergingTime) << endl;



	return 0;
}