#include <iostream>
#include "structures.h"

int main() {
	Input i = reading(std::cin);
	Output o(i);

	std::cout << o;
}
