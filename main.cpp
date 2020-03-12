#include <iostream>
#include "structures.h"

int main() {
	const Input i = reading(std::cin);
	Output o(i);

	std::cout << o;
}
