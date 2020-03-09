#pragma once

namespace myDeque
{
	class deque {
	private:

		double* container = nullptr; /// Raw pointer to the underlying buffer
		                   /// May be NULL if the deque is empty
		
		size_t frontIndex = 0; /// Index of the front in the array
		size_t backIndex = 0;  /// Index of the back in the array
		size_t capacity = 0;   /// Number of elements in the underlying buffer
		size_t startCapacity = 2; /// Size of allocate memory for container

		const double resizeCoefficient = 2;
		void copy(double const*);
		void copyDeque(deque const&);
		void deleteDeque();
		void resize();
		void allocContainer();
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
 
