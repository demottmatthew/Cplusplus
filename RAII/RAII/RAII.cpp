#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void log(std::string str) {
	std::cout << "\n" << str;
}
class RAII {
private:
	char *buff;
	int ID;
	void copy(const RAII &copyFrom) {
		size_t size = sizeof(copyFrom.buff);
		buff = new char[size];
		memcpy(buff, copyFrom.buff, size);
	}
	void allocate(size_t size) {
		buff = new char[size];
	}
	void deallocate() {
		free(buff);
		buff = nullptr;
	}
public:
	static int instanceID;
	RAII() : buff(nullptr) {
		ID = instanceID;
		instanceID++;
		log("\nCreated empty instance of RAII with the instance ID: " + to_string(ID));
	}
	RAII(size_t size) : buff(nullptr) {
		ID = instanceID;
		instanceID++;
		log("\nCreating an allocated instance of RAII with the instance ID " + to_string(ID) + " with size " + to_string(size));
		allocate(size);
		log("Space has been allocated for RAII instance " + to_string(ID) + " at address ");
		cout << static_cast<void*>(buff);
	}
	RAII(const RAII &copyFrom) : buff(nullptr) {
		ID = instanceID;
		instanceID++;
		copy(copyFrom);
		log("\nUsed the copy constructor to copy from ");
		cout << static_cast<void*>(copyFrom.buff) << " to " << static_cast<void*>(buff);

	}
	RAII &operator=(const RAII &stealFrom) {
		copy(stealFrom);
		log("\nCopied from instance " + to_string(stealFrom.ID) + " to ");
		cout << static_cast<void*>(buff);
		return *this;
	}
	RAII &operator=(RAII &&moveFrom) {
		deallocate();
		buff = moveFrom.buff;
		log("\nMoved data from ");
		cout << static_cast<void*>(moveFrom.buff) << " to " << static_cast<void*>(buff);
		moveFrom.buff = nullptr;
		return *this;
	}
	~RAII() {
		log("\nDeallocating memory for instance " + to_string(ID));
		deallocate();
		log("Instance " + to_string(ID) + " has been deallocated");
	}
};
void regularConstructorTest()
{
	log("Regular Instantiation Test");
	RAII emptyTest(20);
	RAII *test1 = new RAII();
	RAII *test2 = new RAII(10);
	RAII *test3 = new RAII(*test2);
	delete test1;
	delete test2;
	delete test3;
}

void copyConstructorTest()
{
	log("Copy Constructor Test");
	std::vector<RAII> instances;
	instances.push_back(RAII(20));
	instances.push_back(RAII(30));
	instances.push_back(RAII(40));
	std::vector<RAII> copy;
	copy = instances;

}

void copyOperatorTest()
{
	log("Copy Operator Test");
	RAII test1 = RAII(10);
	RAII test2 = RAII(10);
	test1 = test2;
}

void moveTest()
{
	log("Move Test");
	RAII test1(20);
	test1 = RAII(20);
	RAII test2 = RAII(20);
}

int RAII::instanceID = 0;
int main() {

	regularConstructorTest();
	copyConstructorTest();
	copyOperatorTest();
	moveTest();
	system("PAUSE");
}

