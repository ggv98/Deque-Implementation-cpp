#pragma once

namespace myDeque
{
	class deque {
	private:

		double* container; /// Raw pointer to the underlying buffer
		                   /// May be NULL if the deque is empty
		
		size_t frontIndex; /// Index of the front in the array
		size_t backIndex;  /// Index of the back in the array
		size_t capacity;   /// Number of elements in the underlying buffer

		const int resize_coefficient = 2;

		void copy(double const*);
		void copyDeque(deque const&);
		void deleteDeque();
		void resize();
	public:
		deque(size_t startCapacity = 0);
		deque(deque const&);
		deque& operator = (deque const&);
		~deque();

		size_t size() const;
		bool empty() const;
		double& operator[](size_t);
		void push_front(double);
		void push_back(double);
		double pop_front();
		double pop_back();
		double back();
		double front();

	};
}
 
