//============================================================================
// Title        : sieve.cpp
// Abstract		: This program uses a well known algorithm to output prime numbers
// Author		: Samuel Roy
// ID			: 6715
// Date			: 5/9/17
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

int* sieve(int userInput) {

	int * numArray = new int [userInput];
	int * primeArray = new int [userInput];

	//for p <- 2 to n
	for(int p = 2; p <= userInput; p++) {

		// do A[p] <- p
		numArray[p] = p;

		//for p <- 2 to sqrt(n)
		for(int p = 2; p <= floor(std::sqrt(userInput)); p++) {

			//do
			if(numArray[p] != 0) {

				//j <- p * p
				int j = p * p;

				//while j<=n
				while(j <= userInput) {

					//do A[j] <- 0
					//j <- j + p
					numArray[j] = 0;
					j = j + p;
				}
			}
		}
	}

	// i <- 0
	int i = 0;

	//for p <- 2 to n
	for(int p = 2; p <= userInput; p++)
	{

		//do if A[p] != 0
		if (numArray[p] != 0) {

			//L[i] <- A[p]
			primeArray[i] = numArray[p];

			//print the array
			cout << primeArray[i] << ", ";

			//i <- i + 1
			i = i + 1;
		}


	}

	//clearing memory
	delete [] numArray;
	delete [] primeArray;

	//return L
	return primeArray;
}

int main() {

	int userInput;

	cout << "Enter a number: ";
	cin >> userInput;

	cout << endl << "Prime numbers: ";
	sieve(userInput);

	system("pause");

	return 0;
}

