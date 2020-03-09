#include "pch.h"

namespace myDeque
{
	///
	/// Constructs and allocates memory for a deque
	///
	deque::deque(size_t startCapacity)
	{
		if (startCapacity <2) {
			capacity = startCapacity;
		}
		else {
			capacity = 2;
		}

		frontIndex = capacity / 2;
		backIndex = frontIndex-1;
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

	///
	/// Copy *other in the deque container
	///
	/// Container memory need to be allocated before call the function
	///
	void deque::copy(double const* other)
	{
			for (int i = frontIndex; i <= backIndex; ++i) {
				container[i] = other[i];
			}
		
	}
	void deque::copyDeque(deque const& dq) {

		container = new double[capacity];
		capacity = dq.capacity;
		frontIndex = dq.frontIndex;
		backIndex = dq.backIndex;
		try {
			copy(dq.container);
		}
		catch (const std::exception & e) {
			delete[] container;
			return;
		}
	}

	///
	/// Copy constructor
	///
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

	///
	/// Destruct dynamic allocate memory
	///
	deque::~deque() {
		deleteDeque();
	}

	///
	/// Returns number of element in deque
	///
	size_t deque::size() const
	{
		return backIndex - frontIndex + 1;
	}

	///
	/// Check if an Deque is empty or not. 
	///
	/// Return Value: The function returns True if the deque is empty 
	/// else it returns False.
	///
	bool deque::empty() const
	{
		return size() == 0;
	}

	///
	/// Returns a reference to the element at given position in the deque container.
	///
	/// \throws if the requested position is out of range by throw an out_of_range exception.
	///
	double& deque::operator[](size_t position)
	{
		if (position >= size() || position < 0) {
			throw std::out_of_range("given position is out of range");
		}
		return container[frontIndex + position];
	}
	///
	/// Resize container capacity
	///
	/// \throws std::bad_alloc If memory allocation fails
	///
	void deque::resize() {
		double* Buffer = new double[capacity*resize_coefficient];

		capacity *= resize_coefficient;
		int newFrontIndex = capacity / 2 - size() / 2;
		int newBackIndex = newFrontIndex;

		try {
			for (int i = frontIndex; i <= backIndex; ++i) {
				Buffer[newBackIndex] = container[i];
				++newBackIndex;
			}
		}
		catch(const std::exception & e){
			delete[] Buffer;
			return;
		}
		frontIndex = newFrontIndex;
		backIndex = newBackIndex - 1;
		delete[] container;
		container = Buffer;
	}
	///
	/// Adds an element to the back of the queue
	///
	/// If there is no space left in the underlying buffer
	/// the function reallocates it.
	///
	/// \throws std::bad_alloc If memory allocation fails
	///
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

	///
	/// Remove and  return item at the front of the deque
	///
	/// The operation only work on non-empty deques
	///
	/// \throws std::exception if the deque empty
	///
	double deque::pop_front() {
		
		if (empty())
			throw std::exception();

		return container[frontIndex++];
	}

	///
	/// Remove and  return item at the back of the deque
	///
	/// The operation only work on non-empty deques
	///
	/// \throws std::exception if the deque empty
	///
	double deque::pop_back() {

		if (empty())
			throw std::exception();

		return container[backIndex--];
	}

	///
	/// Returns the item at the front of the deque
	///
	/// The operation only works on non-empty deques
	///
	/// \throws std::exception if the deque is empty
	///
	double deque::front() {

		if (empty())
			throw std::exception();

		return container[frontIndex];
	}

	///
	/// Returns the item at the back of the deque
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