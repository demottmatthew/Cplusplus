// Homework3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int checkIfUnique(vector<int> v, int n) {
	for (int i = 0; i < v.size(); i++) {
		if (n == v[i]) {
			return 1;
		}
	}
	return 0;
}

int countOccurances(vector<int> v, int n){
	int count = 0;
	for (int i = 0;  i < v.size(); i++) {
		if (v[i] == n)
		{
			count++;
		}
	}
	return count;
}

void getUniqueOccurances(vector<int> v) {
	vector<int> uniqueInts;
	for (int i = 0; i < v.size(); i++)
	{
		if (checkIfUnique(uniqueInts, v[i]) == 0) {
			uniqueInts.push_back(v[i]);
		}

	}
	for (int i = 0; i < uniqueInts.size(); i++) {
		int occurances = 0;
		occurances = countOccurances(v, uniqueInts[i]);
		if (i == 0) {
			if (occurances == 1) {
				cout << uniqueInts[i];
			}
			else {
				cout << uniqueInts[i] << "^" << occurances;
			}
		}
		else {
			if (occurances == 1) {
				cout << "*" << uniqueInts[i];
			}
			else {
				cout << "*" << uniqueInts[i] << "^" << occurances;
			}
			
		}
		
	}
}

int prime(int n) {
	int i = 2;
	bool factorNotFound = true;
	while (factorNotFound && i <= sqrt(n)) {
		if (n % i == 0) {
			factorNotFound = false;
		}
		i++;
	}
	if (factorNotFound == true) {
		return 1;
	}
	else {
		return 0;
	}
}
int smallestFactor(int n) {
	int i = 2;
	int returnVal = 0;
	bool factorNotFound = true;
	while (factorNotFound && i <= sqrt(n)) {
		if (n % i == 0) {
			factorNotFound = false;
			returnVal = i;
		}
		i++;
	}
	if (factorNotFound == true) {
		return 0;
	}
	else {
		return returnVal;
	}
}

int factor(int n, vector<int> factorVector) {
	if (prime(n) == 1)
	{
		factorVector.push_back(n);
		getUniqueOccurances(factorVector);
		return 0;
	}
	int smallestFact = 0;
	smallestFact = smallestFactor(n);
	if (prime(smallestFact) == 1)
	{
		factorVector.push_back(smallestFact);
	}
	else {
		factor(smallestFact, factorVector);
	}
	int factorPair = n / smallestFact;
	factor(factorPair, factorVector);
}
int checkInput(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '0' || s.at(i) == '1' || s.at(i) == '2' || s.at(i) == '3' || s.at(i) == '4' || s.at(i) == '5' || s.at(i) == '6' || s.at(i) == '7' || s.at(i) == '8' || s.at(i) == '9') {

		}
		else {
			return 1;
		}
	}
	return 0;

}

int main() {
	try {
		int number = 0;
		string input;
		while (number == 0) {
			cout << "Enter an integer\n";
			cin >> input;
			if (number < 0 || checkInput(input)) {
				cout << "invalid input\n";
				number = 0;
			}
			else {
				number = stoi(input);
				vector<int> factorVector;
				if (prime(number) == 1)
				{
					cout << number;
				}
				else {
					factor(number, factorVector);
				}
				cout << "\n";
			}
		}
		
	}
	catch (...) {
		cout << "invalid input";
	}
	system("PAUSE");
	return 0;
}

