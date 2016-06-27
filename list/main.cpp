#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>

#include "list.h"

std::string rand_stirng() {
	std::string s = "";
	int n = rand() % 10 + 2;
	for (int i = 0; i < n; i++) {
		s += ('a' + rand() % 20);
	}
	return s;
}

int main() {
	srand(14);
	list a, a1;
	std::list<std::string> b;

	for (int i = 0; i < 30; i++) {
        std::string c = rand_stirng();
		a.push_back(c);
		a1.push_back(c);
	}

	for (auto& i : a) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	auto i = a.begin();
	auto j = a.begin();
	auto pos = a.begin();

	for (int k = 0; k < 5; k++) {
		++i;
	}

	for (int k = 0; k < 10; k++) {
		++j;
	}

	for (int k = 0; k < 11; k++) {
		++pos;
	}

	a.splice(pos, a, i, j);

	for (auto i : a) {
		std::cout << i << ' ';
		b.push_back(i);
	}
	std::cout << std::endl;

	for (;;) {
		int type = rand() % 100;
		std::string s = rand_stirng();
		if (type <= 35) {
			a.push_back(s);
			b.push_back(s);
		} else if (type <= 70) {
			a.push_front(s);
			b.push_front(s);
		} else if (type <= 83) {
			if (!b.empty()) {
				a.pop_back();
				b.pop_back();
			} else {
				
			}
		} else if (type <= 96) {
			if (!b.empty()) {
				a.pop_front();
				b.pop_front();
			} else {

			}
		} else if (type <= 98) {
			a.clear();
			b.clear();
		} else {
			a = list();
			b = std::list<std::string>();
		}

		list::iterator j = a.begin();
		std::list<std::string>::iterator i = b.begin();
		for (; i != b.end(); ++i, ++j) {
			assert(*i == *j);
			if (rand() % 10000 == 0) {
				if (rand() % 2 == 0) {
					std::string s = rand_stirng();
					a.insert(j, s);
					b.insert(i, s);
				} else {
					auto A = a.erase(j);
					auto B = b.erase(i);
					if (B != b.end())
						assert(*A == *B);
					else {

						/* if (rand() % 10 == 0) { */
						/* 	std::cout << "ASSSSSSSSSSSSSSSSSS\n"; */
						/* 	a.erase(j); */
						/* } */

					}
				}
				break;
			}
		}


		assert(a.empty() == b.empty());
		if (!b.empty()) {
			assert(a.back() == b.back());
			assert(a.front() == b.front());
		} else {
		}

		static int cnt = 0;
		cnt++;
		if (cnt % 1000 == 0)
			std::cout << cnt << std::endl;
	}

	for (;;) {
		std::string type;
		std::cin >> type;
		if (type == "back") {
			std::cout << a.back();
		} else if (type == "front") {
			std::cout << a.front();
		} else if (type == "pop_back") {
			a.pop_back();
		} else if (type == "pop_front") {
			a.pop_front();
		} else if (type == "push_back") {
			std::cin >> type;
			a.push_back(type);
		} else if (type == "push_front") {
			std::cin >> type;
			a.push_front(type);
		} else if (type == "empty") {
			std::cout << a.empty();
		} else if (type == "clear") {
			a.clear();
		}
		std::cout << std::endl;
	}

	return 0;
}
