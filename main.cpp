#include <iostream>
#include "structures.h"
#include <random>
#include "Komonyi.h"


void solver(Data& in) {
	std::vector<std::vector<bool>> atDesk{in.desks.size(), std::vector<bool>(in.desks.empty() ? 0 : in.desks[0].size(), false)};
	for (std::size_t i = 0; i < in.desks.size(); ++i)
		for (std::size_t j = 0; j < in.desks[i].size(); ++j)
			atDesk[i][j] = in.desks[i][j] == Desk::unavailable;

}


int main() {
	Data i = reading(std::cin);
	solver(i);

	Komonyi cucc(i);
	
	std::cout << i;
}
