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

struct Pos {
	std::size_t x = -1, y = -1;
};


struct Output {
	std::vector<Pos> developers;
	std::vector<Pos> managers;

	Output() = default;
	Output(const Input& i) : developers(i.developers.size()), managers(i.managers.size()) {}
};

Input reading(std::istream& i);
std::ostream& operator<<(std::ostream& o, const Output& out);
