#include "CornerMasterBuilder.h"

void CornerMasterBuilder::createName() {
	_race_track->setName("Corner Master");
}

void CornerMasterBuilder::makeLayout() {
	std::vector<std::tuple<int, std::string>> corner_master = { 
		{ 4, "straight" }, 
		{ 3, "loose-left" }, 
		{ 1, "tight-right" }, 
		{ 2, "straight" }, 
		{ 3, "straight" }, 
		{ 2, "tight-right" }
	};

	for(auto it = corner_master.begin(); it != corner_master.end(); ++it) {
		_race_track->addToLayout(*it);
	}
}