#include <iostream>
#include "C:\Users\Matthew\Documents\CSI 2320\poly3\poly3\PolyLib\src\poly.h"
#include <string>
#include <vector>
using namespace std;


void main() {
	cout << "Input the first polynomial: ";
	string inputBuffer;
	getline(cin, inputBuffer);
	vector<double> poly1 = parsePolynom(inputBuffer);
    cout << "Input the second polynomial: ";
    getline(cin, inputBuffer);
    vector<double> poly2 = parsePolynom(inputBuffer);
    cout << "Sum is: " << displayPolynom(addPolynomials(poly1,poly2)) << endl;
    cout << "Product is: " << displayPolynom(multiplyPolynomials(poly1, poly2)) << endl;

    cout  << "Press ENTER to continue.";
    getline(cin, inputBuffer);
}