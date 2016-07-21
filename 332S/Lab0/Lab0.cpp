// SimpleProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab0.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char* argv[]){
	if (argc != commArgs)			//Check to make sure correct number of cmmand line arguments is entered
		return usageMessage(argv[progName]);
	
		vector<string> fileStrings;
		int result = fileParse(fileStrings, argv[inFile]);
		if (result != success)		//if unsuccessful parse, return error type
			return result;
		
		vector<int> numbers;		//used for holding the number from the file
		
		//iterate through each character in the file and test if it's a digit
		for (size_t i = 0; i < fileStrings.size(); ++i){
			bool isNum = true;
			for (char c : fileStrings[i]){
				if (!isdigit(c)){
					isNum = false;
				}
			}
			int value;
			
			//if a number is encountered, add it to the vector
			if (isNum == true){
					
					istringstream iss(fileStrings[i]);
					iss >> value;
					numbers.push_back(value);
				}
				else
					cout << fileStrings[i] << endl;
			}
		
		//print out numbers in the vector
		for (size_t i = 0; i < numbers.size(); ++i)
			cout << numbers[i] << endl;
	
		return success;
}

/*
Function that takes a vector and a file and stores all the strings from the file into the vector
otherwise, returns appropriate error
*/
int fileParse(vector<string> &Lines, char * File ){
	ifstream ifs(File);
	if (ifs){				//make sure file is open
		string line, line2;
		while (getline(ifs, line)){
			
				istringstream lineStream(line);		//bind line to lineStream
				
				while (lineStream >> line2){
					Lines.push_back(line2);
			}
		}
	}
	else{
		cout << "File didn't open" << endl;
		cerr << failToOpen << endl;
	}
	return success;
}

int usageMessage(const string &ProgName){
	cout << "Usage: " << ProgName << " <InputFile>" << endl;
	return incorrectCommLineArgs;
}