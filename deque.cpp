#include "pch.h"

namespace myDeque
{
	///
	/// Constructs and allocates memory for a deque
	///
	deque::deque(size_t startCapacity)
	{
		if (startCapacity < 2) {
			capacity = 2;
		}
		else {
			capacity = startCapacity;
		}

		frontIndex = capacity / 2;
		backIndex = frontIndex - 1;
		container = new double[capacity];
	}


	///
	/// Destroys the deque
	///
	/// The object cannot be used anymore after using this function
	///
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


	size_t deque::size() const
	{
		return backIndex - frontIndex + 1;
	}


	bool deque::empty() const
	{
		return size() == 0;
	}


	double& deque::operator[](size_t index)
	{
		if (index >= size() || index < 0) {
			std::cout << "Index out of bound";
			exit(0); //TODO error handling must be consistent
		}
		return container[frontIndex + index];
	}

	void deque::resize() {
		double* oldDeque = container;
		container = new double[capacity];

		capacity *= resize_coefficient;
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

	///
	/// Adds an element to the front of the queue
	///
	/// If there is no space left in the underlying buffer
	/// the function reallocates it.
	///
	/// \throws std::bad_alloc If memory allocation fails
	///
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

		//TODO consider what happens if the queue is empty

		if (empty()) {
			std::clog << "Pop from empty deque" << std::endl;
			return double();
		}

		return container[backIndex--];
	}

	///
	/// Returns the item at the front of the deque
	///
	/// The operation only works on non-empty deques
	/// Behavior on empty deques is undefined
	///
	double deque::front() {
		//if (empty()) {
		//	std::cout << "Empty deque" << std::endl;
		//	return double();
		//}
		assert(!empty());
		return container[frontIndex];
	}


	///
	/// Returns the item at the front of the deque
	///
	/// The operation only works on non-empty deques
	/// 
	/// \throws std::exception if the deque is empty
	///
	double deque::back() {

		if (empty())
			throw std::exception();

		return container[backIndex];
	}
}