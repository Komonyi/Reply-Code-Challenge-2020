
#include <iostream>

#include "structures.h"


Input read(std::istream& i) {
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

	for (auto& dev : in.developers) {
		i >> dev.company >> dev.bonus >> w;
		dev.skills.resize(w);
		for (auto& skill : dev.skills)
			i >> skill;
	}

	i >> w;
	in.managers.resize(w);

	for (auto& man : in.managers) {
		i >> man.company >> man.bonus;
	}

	return in;
}
