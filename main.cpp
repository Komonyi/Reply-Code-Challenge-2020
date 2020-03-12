#include <iostream>
#include "structures.h"

void solver(const Input& in, Output& o) {
	std::vector<std::vector<bool>> atDesk;
	std::size_t dev{}, mans{};
	for (std::size_t i = 0; i < in.desks.size(); ++i) {
		auto& desks = in.desks[i];
		for (std::size_t j = 0; j < desks.size(); ++j) {
			switch(desks[j]) {
				case Desk::manager:
					if (mans < in.managers.size()) {
						o.managers[mans++] = Pos{j, i};
					}
					break;
				case Desk::developer:
					if (dev < in.developers.size()) {
						o.developers[dev++] = Pos{j, i};
					}
					break;
			}
		}
	}
}


int main() {
	const Input i = reading(std::cin);
	Output o(i);

	solver(i, o);

	std::cout << o;
}
