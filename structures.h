#pragma once

#include <vector>

struct Developer {
	std::string company;
	std::size_t bonus;
	std::vector<std::string> skills;
};

struct Mananger {
	std::string company;
	std::size_t bonus;
};

enum Desk : char {
	unavailable = '#',
	developer = '_',
	manager = 'M'
};

struct Input {
	std::vector<std::vector<Desk>> desks;
	std::vector<Developer> developers;
	std::vector<Mananger> managers;
};
