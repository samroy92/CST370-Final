//============================================================================
// Name         : powers-of-2.cpp
// Abstract		: This program uses recursion to calculate 2^n user input
// Author		: Samuel Roy
// ID			: 6715
// Date			: 6/6/17
//============================================================================

#include <iostream>

using namespace std;

//the main recursive function
//returns an int, and has two params
int powerSeries(int input, int answer)
{
	//if the user enters 0, the answer is known to be 1
	if (input == 0)	{
		return 1;
	}

	//likewise if the user enters 1 the answer is known to be the power
	else if (input == 1) {
		return answer;
	}

	//main recursive piece
	else {
		//multiply answer by 2, and recurse function as many times as user input number
		answer = answer * 2;

		//call power series again with decremented input, but passing the stored answer value
		return powerSeries((input - 1), answer);
	}
}

int main() {

	//define user input variable
	int num = 0;

	//ask user to enter an integer, store in num
	cout << "Enter a number: ";
	cin >> num;

	//print out the recursive return of num,2; 2 being the power
	cout << powerSeries(num,2);

	return 0;
}


