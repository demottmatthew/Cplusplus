// Homework2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string startString = "";
	string unit = "";
	string convertTo = "";
	int distance = 0;
	int count = 0;
	while (startString.length() < 3 || (unit.compare("y") != 0 && unit.compare("m") != 0)) {
		try {
			system("CLS");
			if (count > 0) {
				cout << "You have entered an invalid start string or unit to convert to\n";
				cout << "Enter a distance with a unit yards (y) or miles (m): Example: 5 y for five yards\n";
			}
			else {
				cout << "Enter a distance with a unit yards (y) or miles (m): Example: 5 y for five yards\n";
			}
			getline(cin, startString);
			if (startString.length() > 2) {
				cout << "Enter the unit you would like to convert to kilometers (km) or meters (m)\n";
				cin >> convertTo;
				unit = startString.at(startString.length() - 1);
				distance = stoi(startString.substr(0, startString.length() - 2));
				if (unit.compare("m") == 0) {
					if (convertTo.compare("m") == 0) {
						cout << distance * 1609.344 << " meters";
					}
					else if (convertTo.compare("km") == 0) {
						cout << distance * 1.609344 << " kilometers";
					}
					else {
						cout << "invalid unit to convert to\n";
					}
				}
				else if (unit.compare("y") == 0) {
					if (convertTo.compare("m") == 0) {
						cout << distance * 0.9144 << " meters";
					}
					else if (convertTo.compare("km") == 0) {
						cout << distance * 0.0009144 << " kilometers";
					}
					else {
						cout << "invalid unit to convert to\n";
					}
				}
				else {
					cout << "invalid unit\n";
				}
			}
		}
		catch (...) {
			cout << "You have entered an invalid start string or unit to convert to\n";
			startString = "m";
			convertTo = "";
			unit = "";
			distance = 0;
			count++;
		}
	}
	return 0;
}

