#pragma once

#include <vector>
#include <cmath>
#include <limits>
#include <array>

struct Pos {
	static constexpr auto INVALID = std::numeric_limits<std::int32_t>::min();
	std::int32_t x = INVALID, y = INVALID;

	constexpr Pos(std::int32_t x, std::int32_t y) noexcept : x(x), y(y) {}

	constexpr Pos() noexcept = default;

	std::size_t Distance(const Pos& other) const {
	    return std::abs(this->x - other.x) + std::abs(this->y - other.y);
	}

	constexpr bool IsNextTo(const Pos& other) const { return this->Distance(other) == 1; }

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
};

struct Developer {
	std::size_t company;
	std::size_t bonus;
	std::vector<std::size_t> skills;
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
