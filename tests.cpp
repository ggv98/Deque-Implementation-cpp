#include "pch.h"
#include "tests.h"
using namespace myDeque;
bool tests::testPushFront() {
	deque d(4);
	d.push_front(1.2);
	d.push_front(1.0);
	return d.front() == 1;
}
bool tests::testPushBack() {
	deque d(4);
	d.push_back(1.2);
	d.push_back(1.0);
	return d.back() == 1;
}
bool tests::testSize() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.0);
	return d.size() == 2;

}
bool tests::testResize() {
	deque d(1);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	return d.size() == 4;

}
bool tests::testPopBack() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	double arr[] = { 1.3, 1.2, 1.1, 1 };
	for (int i = 0; i < 4; i++) {
		if (d.pop_back() != arr[i]) return false;
	}
	return true;
}
bool tests::testPopFront() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	double arr[] = { 1.0, 1.1, 1.2, 1.3 };
	for (int i = 0; i < 4; i++) {
		if (d.pop_front() != arr[i]) return false;
	}
	return true;
}
bool tests::testReturnToEmptyState() {
	deque d(1);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	for (int i = 0; i < 4; i++) {
		d.pop_back();
	}
	return d.empty() == true && d.size() == 0;
}
bool tests::testFront() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	return d.front() == 1.1;
}
bool tests::testBack() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	return d.back() == 1.3;
}
bool tests::testClear() {
	deque d(16);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.clear();
	return d.size() == 0 && d.empty() == 1;
}
bool tests::testOperatorSquarebrakets() {
	deque d(4);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	double arr[] = { 1.0, 1.1, 1.2, 1.3 };
	for (int i = 0; i < 4; i++) {
		if (d[i] != arr[i]) return false;
	}
	return true;
}

void tests::startTests() {
	std::cout << "Test:1 ->Test push_front: ";
	if (testPushFront()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:2 ->Test push_back: ";
	if (testPushBack()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:3 ->Test back(): ";
	if (testBack()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:4 ->Test Front(): ";
	if (testFront()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:5 ->Test clear(): ";
	if (testClear()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:6 ->Test operator[]: ";
	if (testOperatorSquarebrakets()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:7 ->Test resize: ";
	if (testResize()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:8 ->Test size(): ";
	if (testSize()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:9 ->Test return to empty state: ";
	if (testReturnToEmptyState()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:10 ->Test pop_back(): ";
	if (testPopBack()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;

	std::cout << "Test:11 ->Test pop_front(): ";
	if (testPopFront()) std::cout << " OK!";
	else std::cout << " FAIL!";
	std::cout << std::endl;
}




