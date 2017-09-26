//============================================================================
// Name         : hw8.cpp
// Abstract		: This program finds the number of comparisons in selection and quicksort algorithms
// Author		: Samuel Roy
// ID			: 6715
// Date			: 6/27/17
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int _selectionSortCount = 0;

void selectionSort(int inputArray[],int numLength)
{
	//declare variables
	int first;
	int temp;

	for (int i = (numLength - 1); i > 0; i--) {

		//set first to zero element at the iteration of the for loop
		first = 0;

		for (int j = 0; j <= (i - 1); j++) {

			// if the element j is less than the first input, make element j
			if (inputArray[j] < inputArray[first]) {

				first = j;
				_selectionSortCount++;

			}
		}

		//create a temp varible for first
		temp = inputArray[first];

		//set first to the element at i
		inputArray[first] = inputArray[i];

		// set element i as temp
		inputArray[i] = temp;
	}
}

int _quickSortCount = 0;

void quickSort(int inputArray[], int left, int right) {

	//declare varaibles
	int i = left;
	int j = right;
	int temp;

	//set pivot to the array divided by 2
	int pivot = inputArray[(left + right) / 2];

	while (i <= j) {

		// while element at i is less than pivot, increment i until we reach a value that is greater
		while (inputArray[i] < pivot) {

			//also increment our execution count
			_quickSortCount++;
			i++;
		}

		// while element at j is greator than pivot, decrement j until we reach a value that is less than
		while (inputArray[j] > pivot) {

			//also increment our execution count
			_quickSortCount++;
			j--;
		}

		// when we find that j and i are together, if i is less than j
		if (i <= j) {

			//increment execution count
			_quickSortCount++;

			//set temp variable to element at i
			temp = inputArray[i];

			//swap the two values
			inputArray[i] = inputArray[j];
			inputArray[j] = temp;

			//increment and decrement i and j
			i++;
			j--;
		}

	}

	//continue recursion for each segment
	if (left < j) {
		quickSort(inputArray, left, j);
	}

	if (i < right) {
		quickSort(inputArray, i, right);
	}

}

int main() {

	// declare input variable
	int inputDataNum;

	//ask user to enter integer value
	cout << "Enter input data number: ";
	cin >> inputDataNum;

	//declare input max value variable
	int inputMaxVal;

	//ask user to enter integer value
	cout << endl << "Enter maximum value: ";
	cin >> inputMaxVal;

	cout << "====================================" << endl;
	cout << "Generating input data. . ." << endl;

	//allocate dynamic inputArrayay with size inputData
	int *randData = new int[inputDataNum];

	//create stream file
	ofstream myfile;
	//open file for writing
	myfile.open("input.txt");

	//loop through entire inputArrayay until input file is populated
	for(int i = 0; i < inputDataNum; i++) {
		randData[i] = rand()%(inputMaxVal + 1);
		myfile << randData[i] << " ";
	}

	//close file for writing
	myfile.close();

	cout << "Done." << endl;

	//run sort algorithms on input inputArrayay
	selectionSort(randData, inputDataNum);
	quickSort(randData, 0, inputDataNum);

	//delete the inputArray
	delete [] randData;

	//print out the determined execution counts
	cout << "====================================" << endl;
	cout << "Selection sort performance" << endl;
	cout << "Number of executions: " << _selectionSortCount << " times" << endl;
	cout << "====================================" << endl;

	cout << "Quicksort performance" << endl;
	cout << "Number of executions: " << _quickSortCount << " times" << endl;
	cout << "====================================" << endl;

	return 0;
}
