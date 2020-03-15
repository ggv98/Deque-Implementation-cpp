#pragma once
#include <unordered_set>
#include <cstring>

namespace myDeque
{
	class deque {
	private:

		double* container = nullptr; /// Raw pointer to the underlying buffer
		                             /// May be NULL if the deque is empty
		
		size_t frontIndex = 0;		/// Index of the front in the array
		size_t backIndex = 0;		/// Index of the back in the array
		size_t capacity = 0;		/// Number of elements in the underlying buffer
		size_t startCapacity = 2;   /// Size of allocate memory for container

		const double resizeCoefficient = 2;

		static const std::string logfile;   /// Name of log file
											/// Record data for allocate and delete memory
																					
		static std::unordered_set<void*> allocMemory; /// record addres of allocate and not delete memory

		void copy(double const*);
		void copyDeque(deque const&);
		void deleteDeque();
		void resize();
		void allocContainer();

	public:
		void* operator new (size_t count);
		void* operator new[] (size_t count);
		void operator delete (void* ptr);
		void operator delete[](void* ptr);

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
		double back() const;
		double front() const;
		void clear();
		void print();

		static void checkMemory();
	};

	
}
 
