#pragma once

#include <vector>

struct Developer {
	std::size_t company;
	std::size_t bonus;
	std::vector<std::size_t> skills;
};

struct Mananger {
	std::size_t company;
	std::size_t bonus;
};

enum class Desk : char {
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
