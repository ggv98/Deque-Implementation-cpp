#include "pch.h"

void* operator new (size_t count) {
	void* p = malloc(count);
	//std::cout << "global operator new adress: " << p << std::endl;
	return p;
}


void* operator new[](size_t count) {
	void* p = malloc(count);
	//std::cout << "global operator new[] adress: " << p << std::endl;;
	return p;
}


void operator delete[](void* ptr) {
	//std::cout << "global operator delete[] adress: " << ptr << std::endl;
	free(ptr);
}


void operator delete (void* ptr) {
	//std::cout << "global operator delete adress: " << ptr << std::endl;
	free(ptr);
}

int main() {

	tests test;
	test.startTests();

	///
	/// test overload new and delete methods
	///
	myDeque::deque* p = new myDeque::deque[100];
	delete[] p;
	myDeque::deque::checkMemory();
	
}