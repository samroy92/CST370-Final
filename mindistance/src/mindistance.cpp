//============================================================================
// Title        : mindistance.cpp
// Abstract		: This program finds minimum distances
// Author		: Samuel Roy
// ID			: 6715
// Date			: 4/26/17
//============================================================================

#include <iostream>
#include <array>
using namespace std;

int main() {

	//declare array of 10 integers
	int myNumber[10];


	//ask user to enter numbers
	cout << "Enter 10 numbers: ";

	//collect all 10 numbers seperated by space
	for (int i = 0; i < 10; i++)
	{
		cin >> myNumber[i];
	}

	//declare temp integer for array sort
	int tempInt;

	// sort the array

	//sort array in ascending order
	for (int j = 0; j < 9; j++)
	{
		for (int k = 0; k < 9; k++)
		{
			if(myNumber[k] > myNumber[k + 1])
			{
				tempInt = myNumber[k];
				myNumber[k] = myNumber[k + 1];
				myNumber[k + 1] = tempInt;

			}

		}
	}

	//set number difference thresholds
	int currentDiff = 0;
	int startingDiff = 99999;

	//compare distances between values
	for (int j = 0; j < 10; j++)
	{
		//make the current difference the first pair
		currentDiff = abs(myNumber[j+1] - myNumber[j]);

		if((currentDiff < startingDiff) && (currentDiff != 0))
		{
			//set the starting difference to the current if it's smaller
			startingDiff = currentDiff;
		}

	}

	cout << endl;

	//output answers
	cout << "Min distance: " << startingDiff << endl;

	//for each potential answer in array, output the two numbers that satisfied the minimum
	for (int i = 0; i < 10; i++)
	{
		if(abs(myNumber[i+1] - myNumber[i]) == startingDiff)
		{
			cout << "Two numbers for min distance: " << myNumber[i] << ", " << myNumber[i + 1] << endl;
		}
	}

	return 0;
}
