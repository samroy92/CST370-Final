//============================================================================
// Name         : hw12.cpp
// Abstract		: This program implements coin row dynamic programming
// Author		: Samuel Roy
// ID			: 6715
// Date			: 8/1/17
//============================================================================

#include <iostream>
#include <string>
using namespace std;



int max(int a, int b) {
  if(a > b) {
	  return a;
  }
  else {
	  return b;
  }
}

void findCoinSolutions(int data[], int n) {

	int maxOne = 0;
	int maxTwo = 0;


	for(int i = 0; i < n; i++) {
		if(maxOne < data[i]) {
			maxTwo = maxOne;
			maxOne = data[i];
		}
		else if (maxTwo > data[i]) {
			maxTwo = data[i];
		}

	}

	for(int i = 0; i < n; i++) {
		if(data[i] == maxOne) {
			cout << i << ", ";
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(data[i] == maxTwo) {
			cout << i << ", ";
			break;
		}
	}

	cout << "1";
}

int coin_row(int data[], int n) {

  int * inputArray = new int[n + 1];

  for(int i = 0; i < n; i++) {
	  inputArray[i + 1] = data[i];
  }

  int * funcArray = new int[n + 1];
  funcArray[0] = 0;
  funcArray[1] = inputArray[1];


  for(int i = 2; i <= n; i++) {

	  int operand = inputArray[i] + funcArray[i - 2];


      funcArray[i] = max(operand, funcArray[i - 1]);

    }

  findCoinSolutions(funcArray, (n + 1));

  return funcArray[n];
}


int main() {

	int iNum;


	cout << "Number of coin(s): ";
	cin >> iNum;

	int * coins = new int[iNum];

	cout << "Array: ";

	for (int i = 0; i < iNum; i++)
	{
		cin >> coins[i];
	}




	int answer = coin_row(coins, iNum);

	cout << endl;
	cout << answer;

	return 0;
}
