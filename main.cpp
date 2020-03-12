#include <iostream>
#include "structures.h"
#include <random>
#include "Komonyi.h"


void solver(Data& in) {
	std::size_t devPlaces{}, manPlaces{};
	std::vector<std::vector<bool>> atDesk{in.desks.size(), std::vector<bool>(in.desks[0].size(), false)};
	for (std::size_t i = 0; i < in.desks.size(); ++i)
		for (std::size_t j = 0; j < in.desks[0].size(); ++j) {
			atDesk[i][j] = in.desks[i][j] == Desk::unavailable;
			if (in.desks[i][j] == Desk::developer) ++devPlaces;
			else if (in.desks[i][j] == Desk::manager) ++manPlaces;
		}
	
	std::mt19937 e2(1002);

	
	std::uniform_int_distribution<> devDist(0, in.developers.size()-1);
	std::uniform_int_distribution<> manDist(0, in.managers.size()-1);
	std::uniform_int_distribution<> deskXDist(0, in.desks.size()-1);
	std::uniform_int_distribution<> deskYDist(0, in.desks[0].size()-1);

	std::size_t success{};

	while (success < in.developers.size() && devPlaces > 0) {
		std::size_t devIndx{};
		while(in.developers[devIndx = devDist(e2)].is_positioned());
		std::int32_t x{}, y{};
		while(atDesk[x = deskXDist(e2)][y = deskYDist(e2)] || in.desks[x][y] != Desk::developer);
		
		atDesk[x][y] = true;
		++success, --devPlaces;

		in.developers[devIndx].pos = Pos{y, x};
	}

	success = 0;
	while (success < in.managers.size() && manPlaces > 0) {
		std::size_t manIndx{};
		while(in.managers[manIndx = manDist(e2)].is_positioned());
		std::int32_t x{}, y{};
		while(atDesk[x = deskXDist(e2)][y = deskYDist(e2)] || in.desks[x][y] != Desk::manager);
		
		atDesk[x][y] = true;
		++success, --manPlaces;

		in.managers[manIndx].pos = Pos{y, x};
	}
}


int main() {
	Data i = reading(std::cin);
	solver(i);

	Komonyi cucc(i);
	
	std::cout << i;
}
