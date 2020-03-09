#include "pch.h"

int main() {
	myDeque::deque d(1);
	d.push_back(1.2);
	d.push_front(1.1);
	d.push_back(1.3);
	d.push_front(1.0);
	d.push_back(1.4);
	d.push_front(0.9);
	d.push_back(1.5);
	d.push_front(0.8);
	d.push_back(1.6);
	d.push_back(1.7);
	d.push_back(1.8);
	for (int i = 0; i < 11; i++) {
		std::cout << d.pop_back() << std::endl;
	}
	std::cout << d.empty() << std::endl;
	std::cout << d.size() << std::endl;
	std::cout << "starts second part" << std::endl;
	d.push_front(0.9);
	d.push_back(1.5);
	//d.push_front(0.8);
	//d.push_back(1.6);

	std::cout << d.empty()<<std::endl;
	std::cout << d.size()<<std::endl;

	for (int i = 0; i < 1; i++) {
		std::cout << d[i] << std::endl;
	}

}