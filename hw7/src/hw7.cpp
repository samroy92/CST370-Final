//============================================================================
// Name        : hw7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void printInfo(int array[25][25], bool mark[], int numVertices)
{
	cout << "Number of vertices: " << numVertices << endl;

	cout << "Mark array: ";
	for(int i = 0; i < numVertices; i++) {
			cout << mark[i];
		}

	cout << endl;

	cout << "txt file: " << endl;
	for(int i = 0; i < numVertices; i++) {
		for(int j = 0; j < numVertices; j++) {
			cout << array[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void zeroMark(bool mark[], int queue[], int numVertices)
{
	//zero out mark array
	for(int i = 0; i < numVertices; i++) {
		mark[i] = false;
		queue[i] = 0;
	}
}

void bfirstSearch(int array[25][25], int queue[], bool mark[], int numVertices, int startVertices)
{

	int count = 0;

	for(int j = 0; j < numVertices; j++)
	{
		mark[startVertices] = true;

		if(array[startVertices][j] == 1)
		{
			if(mark[j] == false)
			{
				mark[j] = true;
				queue[count] = j;
				count ++;

				cout << j << " -> ";

			}
		}
	}


	for(int i = 0; i < count; i++) {
		if(mark[i] == true)
		{
			bfirstSearch(array, queue, mark, numVertices, queue[i]);
		}

	}


}

int main() {

	//declare string variable to enter filename
	string fileName;

	//ask for file name, store the variable with cin
	cout << "Enter input file name:";
	getline(cin, fileName);

	//open file stream variable
	ifstream inFile (fileName);

	//declare array to store the read file, maximum of 50 lines and 2 entries per line
	int numVertices;

	int startVertex;

	cout << "Enter start vertex: ";
	cin >> startVertex;


	int lineData[25][25];
	bool mark[numVertices];
	int queue[numVertices];

	// if the file is open
	if(inFile.is_open()) {
		//declare string variable
		string str;

	int lineNum = 0;
		//while there exists another line in the file to loop through
		while(getline(inFile, str)) {

			//string cin variable
			istringstream intLines(str);

			//If the line number is first, it is the Vertices number
			if(lineNum == 0) {
				intLines >> numVertices;
			}

			//Else, read the file and save into lineData array starting at element 0
			else {
				int i = 0;

				//Saving lineData array, starting the element at zero. 2 minus the first lines
				while(intLines >> lineData[lineNum - 1][i]) {
					i++;
				}


			}
			//increment line number
			lineNum++;
		}
	}
	//catch in case file can't be opened
	else {
		cout << "File not found." << endl;
	}


	zeroMark(mark, queue, numVertices);
	//printInfo(lineData, mark, numVertices);

	cout << "0 -> ";
	bfirstSearch(lineData, queue, mark, numVertices, startVertex);

	cout << endl;


	return 0;
}


