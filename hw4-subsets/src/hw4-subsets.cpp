//============================================================================
// Name         : hw4-subsets.cpp
// Abstract		: This program uses recursion to display the subset of character string
// Author		: Samuel Roy
// ID			: 6715
// Date			: 5/23/17
//============================================================================

#include <iostream>
#include <string>

using namespace std;

//recursive function
//takes in current characters, the user input string, and integer of num characters user input
void recursiveSubset(string curChar, string strInput, int numChars) {

	//print out the current character which at first is the empty set {}
	cout << "{" << curChar << "}" << endl;

	// for loop iterating through the string length
	for (int i = 0; i < strInput.length(); i++) {

		// create variable for next character in the string array (current + length)
		string nextChar = curChar + strInput[i];

		// create variable for remainingChar
		string remainingChars = strInput.substr(i + 1);

		//recursively call the function with nextChar, remaining string and number of chars from user input
		recursiveSubset(nextChar, remainingChars, numChars);
  }

}

int main() {

	//set variables to default
	int numChars = 0;
	string charString = "";

	//get user input
	cout << "Number of input characters: ";
	cin >> numChars;
	cin.ignore();

	//get user character input
	cout << "Enter " << numChars << " characters [i.e. abcd]: ";
	getline(cin, charString);

	//call recursive function
	recursiveSubset("",charString, numChars);

	return 0;
}
