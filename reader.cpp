
#include <iostream>

#include "structures.h"
#include <map>

Data reading(std::istream& i) {
	Data in;
	(i >> in.desksSize.x >> in.desksSize.y).ignore(4, '\n');
	
	in.desks.resize(in.desksSize.x, std::vector<Desk>(in.desksSize.y));

	for (auto& deskLine : in.desks) {
		std::string str;
		std::getline(i, str);
		std::size_t i{}; 
		for (auto& desk : deskLine) {
			desk = static_cast<Desk>(str[i++]);
		}
	}

	std::size_t tmp;
	i >> tmp;
	in.developers.resize(tmp);

	std::map<std::string, std::size_t> companies;
	std::map<std::string, std::size_t> skills;
	for (auto& dev : in.developers) {
		std::string comp, ski;
		i >> comp >> dev.bonus >> tmp;
		dev.company = companies.emplace(comp, companies.size()).first->second;
		
		for (std::size_t x = 0; x < tmp; ++x) {
			i >> ski;
			dev.skills.emplace(skills.emplace(ski, skills.size()).first->second);
		}
	}

	i >> tmp;
	in.managers.resize(tmp);

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
