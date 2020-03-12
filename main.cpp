#include <iostream>
#include "structures.h"
#include <random>


void solver(Data& in) {
	std::vector<std::vector<bool>> atDesk{in.desks.size(), std::vector<bool>(in.desks[0].size(), false)};
	for (std::size_t i = 0; i < in.desks.size(); ++i)
		for (std::size_t j = 0; j < in.desks[0].size(); ++j)
			atDesk[i][j] = in.desks[i][j] == Desk::unavailable;

}


int main() {
	Data i = reading(std::cin);
	solver(i);
	
	std::cout << i;
}
