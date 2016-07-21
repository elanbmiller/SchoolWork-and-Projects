#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum indices {progName, inFile, commArgs};
enum event {success = 0, failToOpen = 1, incorrectCommLineArgs = -1, };		//assigns values to be returned for success and specific failures
int fileParse(vector<string> &Lines, char * File);	//function to parse file
int usageMessage(const string &ProgName);			//function to tell user how to run program
