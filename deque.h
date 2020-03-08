
#pragma once
#include "pch.h"
namespace myDeque
{
	class deque {
	private:

		double* container;
		int frontIndex, backIndex, capacity;

		const int resize_coefficient = 2;

		void copy(double const*);
		void copyDeque(deque const&);
		void deleteDeque();
		void resize();
	public:
		deque(int startCapacity = 16);
		deque(deque const&);
		deque& operator = (deque const&);
		~deque();

		int size();
		bool empty();
		double& operator[](int);
		void push_front(double);
		void push_back(double);
		double pop_front();
		double pop_back();
		double back();
		double front();
	};
}
 
