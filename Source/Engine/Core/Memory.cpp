#include "Memory.h"
#include <iostream>

using namespace std;

void* operator new (size_t size) {
	cout << "Allocated: " << size << endl;

	return malloc(size);
}

void operator delete (void* memAddress, size_t size) {
	cout << "Deallocated: " << size << endl;

	free(memAddress);
}