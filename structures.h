#pragma once

#include <vector>

struct Developer {
	std::string company;
	std::size_t bonus;
	std::vector<std::string> skills;
};

enum Desk : char {
	unavailable = '#',
	developer = '_',
	proj_manager = 'M'
};

struct Input {
	std::vector<std::vector<Desk>> desks;
	std::vector<Developer> developers;
};
