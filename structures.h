#pragma once

#include <vector>
#include <cmath>

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

    Pos(size_t x, size_t y) : x(x), y(y) {

    }

    Pos() {}

    std::size_t Distance(Pos& other){
	    return std::abs(this->x - other.x) + std::abs(this->y - other.y);
	}

	bool IsNextTo(Pos& other){ return this->Distance(other) == 1; }
};


struct Output {
	std::vector<Pos> developers;
	std::vector<Pos> managers;

	Output() = default;
	Output(const Input& i) : developers(i.developers.size()), managers(i.managers.size()) {}
};

Input reading(std::istream& i);
std::ostream& operator<<(std::ostream& o, const Output& out);
