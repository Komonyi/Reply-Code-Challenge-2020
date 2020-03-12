
#include <iostream>

#include "structures.h"
#include <map>

Data reading(std::istream& i) {
	Data in;
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

std::ostream& operator<<(std::ostream& o, const Data& out) {
	for (auto& dev : out.developers) {
		if (dev.pos.x == -1) o << "X\n";
		else o << dev.pos.x << " " << dev.pos.y << "\n";
	}
	for (auto& man : out.managers) {
		if (man.pos.x == -1) o << "X\n";
		else o << man.pos.x << " " << man.pos.y << "\n";
	}
	return o;
}
