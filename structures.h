#pragma once

#include <vector>
#include <cmath>



struct Pos {
	std::int32_t x = -1, y = -1;

    Pos(std::int32_t x, std::int32_t y) : x(x), y(y) {

    }

    Pos() {}

    std::size_t Distance(Pos& other){
	    return std::abs(this->x - other.x) + std::abs(this->y - other.y);
	}

	bool IsNextTo(Pos& other){ return this->Distance(other) == 1; }
};

struct Developer {
	std::size_t company;
	std::size_t bonus;
	std::vector<std::size_t> skills;
	Pos pos;
};



struct Mananger {
	std::size_t company;
	std::size_t bonus;
	Pos pos;
};

enum class Desk : char {
	unavailable = '#',
	developer = '_',
	manager = 'M'
};

struct Data {
	std::vector<std::vector<Desk>> desks;
	std::vector<Developer> developers;
	std::vector<Mananger> managers;
};

Data reading(std::istream& i);
std::ostream& operator<<(std::ostream& o, const Data& out);
