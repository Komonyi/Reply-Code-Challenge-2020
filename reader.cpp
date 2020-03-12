
#include <iostream>

#include "structures.h"
#include <map>

Input reading(std::istream& i) {
	Input in;
	std::size_t w, h;
	(i >> w >> h).ignore(4, '\n');
	
	in.desks.resize(h, std::vector<Desk>{w});

	for (auto& deskLine : in.desks) {
		std::string str;
		std::getline(i, str);
		std::size_t i{}; 
		for (auto& desk : deskLine) {
			desk = static_cast<Desk>(str[i++]);
		}
	}

	i >> w;
	in.developers.resize(w);

	std::map<std::string, std::size_t> companies;
	std::map<std::string, std::size_t> skills;
	for (auto& dev : in.developers) {
		std::string comp, ski;
		i >> comp >> dev.bonus >> w;
		dev.company = companies.emplace(comp, companies.size()).first->second;
		
		dev.skills.resize(w);
		for (auto& skill : dev.skills) {
			i >> ski;
			skill = skills.emplace(ski, skills.size()).first->second;
		}
	}

	i >> w;
	in.managers.resize(w);

	for (auto& man : in.managers) {
		std::string comp;
		i >> comp >> man.bonus;
		man.company = companies.emplace(comp, companies.size()).first->second;
	}

	return in;
}

std::ostream& operator<<(std::ostream& o, const Output& out) {
	for (auto& pos : out.developers) {
		if (pos.x == -1) o << "X\n";
		else o << pos.x << " " << pos.y << "\n";
	}
	for (auto& pos : out.managers) {
		if (pos.x == -1) o << "X\n";
		else o << pos.x << " " << pos.y << "\n";
	}
	return o;
}
