#include "pch.h"
namespace myDeque
{
	deque::deque(int startCapacity)
	{
		if (startCapacity <= 1) {
			capacity = 2;
		}
		else {
			capacity = startCapacity;
		}

		frontIndex = capacity / 2;
		backIndex = frontIndex - 1;
		container = new double[capacity];
	}


	void deque::deleteDeque() {
		delete[] container;
	}

	void deque::copy(double const* other)
	{
		for (int i = frontIndex; i <= backIndex; ++i) {
			container[i] = other[i];
		}

	}

	void deque::copyDeque(deque const& dq) {
		capacity = dq.capacity;
		frontIndex = dq.frontIndex;
		backIndex = dq.backIndex;
		container = new double[capacity];
		copy(dq.container);
	}


	deque::deque(deque const& dq) {
		copyDeque(dq);
	}

	deque& deque::operator=(deque const& dq) {
		if (this != &dq) {
			deleteDeque();
			copyDeque(dq);
		}
		return *this;
	}

	deque::~deque() {
		deleteDeque();
	}


	int deque::size()
	{
		return backIndex - frontIndex + 1;
	}


	bool deque::empty()
	{
		return size() == 0;
	}


	double& deque::operator[](int index)
	{
		if (index >= size() || index < 0) {
			std::cout << "Index out of bound";
			exit(0);
		}
		return container[frontIndex + index];
	}

	void deque::resize() {
		double* oldDeque = container;
		capacity *= resize_coefficient;
		container = new double[capacity];
		int newFrontIndex = capacity / 2 - size() / 2;
		int newBackIndex = newFrontIndex;
		for (int i = frontIndex; i <= backIndex; ++i) {
			container[newBackIndex] = oldDeque[i];
			++newBackIndex;
		}
		frontIndex = newFrontIndex;
		backIndex = newBackIndex - 1;
		delete[] oldDeque;
	}

	void deque::push_back(double data) {
		if (backIndex == capacity - 1) {
			resize();
		}
		container[++backIndex] = data;
	}


	void deque::push_front(double data) {
		if (frontIndex == 0) {
			resize();
		}
		container[--frontIndex] = data;
	}

	double deque::pop_front() {
		if (empty()) {
			std::cout << "Pop from empty deque" << std::endl;
			return double();
		}
		return container[frontIndex++];
	}

	double deque::pop_back() {
		if (empty()) {
			std::cout << "Pop from empty deque" << std::endl;
			return double();
		}
		return container[backIndex--];
	}

	double deque::front() {
		if (empty()) {
			std::cout << "Empty deque" << std::endl;
			return double();
		}
		return container[frontIndex];
	}

	double deque::back() {
		if (empty()) {
			std::cout << "Empty deque" << std::endl;
			return double();
		}
		return container[backIndex];
	}
}