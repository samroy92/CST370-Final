//============================================================================
// Name         : hw11.cpp
// Abstract		: This program implements heap array
// Author		: Samuel Roy
// ID			: 6715
// Date			: 7/25/17
//============================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
vector<string> makeArray(int size)
{
	string rawInput;
	vector<string> userInputNums;

	cout << "Enter numbers: ";
	while(cin >> rawInput)
	{
		cout << "!";
		userInputNums.push_back(rawInput);

		cin.ignore();
	}

	return userInputNums;
}

bool isHeap(vector<int> array)
{
	return false;
}

void printArray(vector<string> array)
{
	cout << "HERE!";
	for(int i = 0; i < array.size(); i++)
	{
		cout << array[i] << ", ";
	}
}*/

void printArray(int arr[], int size)
{
	for(int k = 0; k < size; k++) {
		cout << arr[k] << ", ";
	}
}

bool isHeap(int arr[], int size)
{
	for(int i = 0; i <= (size - 2)/2; i++)
	{
		if(arr[2*i + 1] >  arr[i]) {
			return false;
		}
		if(arr[2*i + 2] > arr[i]) {
			return false;
		}
	}

	return true;
}

int main() {

	int userInputSize;

	cout << "Input size: ";
	cin >> userInputSize;

	int *heapData = new int[userInputSize];

	for(int i = 0; i < userInputSize; i++) {
		cout << "Enter entry: ";
		cin >> heapData[i];
	}

	if(isHeap(heapData, userInputSize))	{
		cout << "This is a heap." << endl;
	}
	else {
		cout << "This is NOT a heap." << endl;
	}
	//printArray(heapData, userInputSize);
	int userInputChoice = 0;

	while(userInputChoice != 3)	{

		cout << "Select an operation" << endl;
		cout << "\t1: Insert a number" << endl;
		cout << "\t2: Delete the max" << endl;
		cout << "\t3: Heapsort & Quit" << endl;



		cin >> userInputChoice;

		if(userInputChoice == 1) {

			int userNum;
			int *newHeap = new int[userInputSize + 1];

			for(int k = 0; k < userInputSize; k++) {
				newHeap[k] = heapData[k];
			}

			cout << "Enter a number: ";
			cin >> userNum;

			newHeap[userInputSize] = userNum;
			userInputSize++;

			delete [] heapData;
			heapData = new int[userInputSize];

			for(int k = 0; k < userInputSize; k++) {
				heapData[k] = newHeap[k];
			}

			delete [] newHeap;


			cout << "Updated heap: ";
			printArray(heapData, userInputSize);

		}
		else if(userInputChoice == 2) {
			//deleteMax(heapData)
		}
		else if(userInputChoice == 3) {
			int temp;

			for (int i = userInputSize; i >= 2; i--)
			{
				temp = heapData[i];
				heapData[i] = heapData[1];
				heapData[1] = temp;
			}

			printArray(heapData, userInputSize);
		}
	}

	return 0;
}



