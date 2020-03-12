#ifndef REPLY_CODE_CHALLENGE_2020_STRUCTURES_H
#define REPLY_CODE_CHALLENGE_2020_STRUCTURES_H

#include <vector>
#include <cmath>
#include <limits>
#include <array>
#include <set>
#include <iostream>

struct Pos {
	static constexpr auto INVALID = std::numeric_limits<int>::min();
	int x = INVALID, y = INVALID;

	constexpr Pos(int x, int y) noexcept : x(x), y(y) {}

	constexpr Pos() noexcept = default;

	std::size_t Distance(const Pos& other) const {
	    return std::abs(this->x - other.x) + std::abs(this->y - other.y);
	}

	bool IsNextTo(const Pos& other) const { return this->Distance(other) == 1; }

	constexpr bool is_valid() const {
		return x != INVALID;
	}

	constexpr bool is_in_bounds(const Pos& max) const {
		return x >= 0 && y >= 0 && x < max.x && y < max.y;
	}

	constexpr static std::array<Pos, 4> neighbour_coords() {
		return {{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};
	}

	constexpr static std::array<Pos, 4> neighbours(const Pos& p) {
		return {{{p.x, p.y-1}, {p.x-1, p.y}, {p.x, p.y+1}, {p.x+1, p.y}}};
	}

	Pos operator+(const Pos& oth) const {
		return {x + oth.x, y + oth.y};
	}

	friend std::ostream& operator<<(std::ostream& o, const Pos& p) {
		return o << '{' << p.y << ',' << p.x << '}';
	}
};

struct Developer {
	std::size_t company;
	std::size_t bonus;
	std::set<std::size_t> skills;
	Pos pos;

	bool is_positioned() const {
		return pos.is_valid();
	}
};



struct Mananger {
	std::size_t company;
	std::size_t bonus;
	Pos pos;

	bool is_positioned() const {
		return pos.is_valid();
	}
};

enum class Desk : char {
	unavailable = '#',
	developer = '_',
	manager = 'M'
};

struct Data {
	Pos desksSize;
	std::vector<std::vector<Desk>> desks;
	std::vector<Developer> developers;
	std::vector<Mananger> managers;
};

Data reading(std::istream& i);
std::ostream& operator<<(std::ostream& o, const Data& out);

#endif //REPLY_CODE_CHALLENGE_2020_STRUCTURES_H
