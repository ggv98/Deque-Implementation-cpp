#include "pch.h"

namespace myDeque
{
	///
	/// Construct an empty deque
	///
	deque::deque(size_t _startCapacity){
		if (_startCapacity > 0) {

				startCapacity = _startCapacity;
			
		}
		
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

	///
	/// Clone deque: dq 
	///
	/// \throws std::bad_alloc If memory allocation fails
	///
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

	///
	/// Operator = 
	///
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
		if (empty()) return 0;

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
		return container == nullptr;
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

		double* Buffer = new double[capacity*resizeCoefficient];
		capacity *= resizeCoefficient;

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
	/// Allocates memory for a deque and set deque variables
	///
	/// \throws std::bad_alloc If memory allocation fails
	///
	void deque::allocContainer()
	{
		container = new double[startCapacity];
		capacity = startCapacity;
		frontIndex = capacity / 2;
		backIndex = frontIndex;
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
		if (empty()) {
			allocContainer();
			container[backIndex] = data;
		}
		else {
			while (backIndex == capacity - 1) {
				resize();
			}
			container[++backIndex] = data;
		}
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
		if (empty()) {
			allocContainer();
			container[frontIndex] = data;
		}
		else {
			while (frontIndex == 0) {
				resize();
			}
			container[--frontIndex] = data;
		}
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

		if (size() == 1) {
			double tmp = container[frontIndex];
			clear();
			return tmp;
		}

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
		if (size() == 1) {
			double tmp = container[backIndex];
			clear();
			return tmp;
		}

		return container[backIndex--];
	}

	///
	/// Returns the item at the front of the deque
	///
	/// The operation only works on non-empty deques
	///
	/// \throws std::exception if the deque is empty
	///
	double deque::front() const {

		if (empty())
			throw std::exception();

		return container[frontIndex];
	}

	///
	/// Delete deque and return it in empty state
	///
	/// Result : All the elements of the deque are removed ( or destroyed )
	///
	void deque::clear()
	{
		delete[] container;
		container = nullptr;
		capacity = 0;
		frontIndex = 0;
		backIndex = 0;
	}

	void deque::print()
	{
		std::cout <<"container:"<< std::endl;
		for (int i = 0; i < capacity; i++) {
			std::cout << i << ": "<< container[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << "frontIndex: " << frontIndex
			<< "backIndex: " << backIndex
			<< "capacity" << capacity << std::endl;
	}

	///
	/// Returns the item at the back of the deque
	///
	/// The operation only works on non-empty deques
	/// 
	/// \throws std::exception if the deque is empty
	///
	double deque::back() const{

		if (empty())
			throw std::exception();

		return container[backIndex];
	}
}