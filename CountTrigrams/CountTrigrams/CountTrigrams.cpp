// CountTrigrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

string readFile(string filepath) {
	int count = 0;

	string fileString, line = "";

	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			fileString += line;
		}
		
		myfile.close();
	} else
	{
		cout << "Error: File " << filepath << " could not be opened. \n\n";
		system("PAUSE");
		exit(1);
	}
	return fileString;
}
void findTrigrams(string wordString) {
	unordered_map<string, int> wordMap;
	for (int i = 0; i < wordString.length() - 2; i++)
	{
		string trigram = wordString.substr(i, 3);
		unordered_map<std::string, int>::const_iterator find = wordMap.find(trigram);
		if (wordMap.find(trigram) == wordMap.end()) {
			wordMap.insert({ trigram, 1 });
		}
		else {
			wordMap.at(find->first) += 1;
		}
	}
	for (auto& x : wordMap) {
		cout << x.first << ": " << x.second << endl;
	}
}
int main()
{
	string filepath = "C:\\Users\\Matthew\\Documents\\CSI 2320\\CountTrigrams\\wordFile.txt";
	string wordString;
	int choice;
	cout << "1) Enter string\n" << "2) Read from file (file path and name is hard coded)\n" << "Enter the choice you want\n";
	cin >> choice;
	if (choice == 1) {
		cout << "Enter the string\n";
		cin.ignore();
		getline(cin, wordString);
	}
	else if (choice == 2) {
		wordString = readFile(filepath);
	}
	findTrigrams(wordString);
	system("PAUSE");
	return 0;
}

