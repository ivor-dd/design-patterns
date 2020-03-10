#include "DragMasterBuilder.h"

void DragMasterBuilder::createName() {
	_race_track->setName("Drag Master");
}

void DragMasterBuilder::makeLayout() {
	std::vector<std::tuple<int, std::string>> drag_master = { 
		{ 2, "straight" }, 
		{ 3, "loose-left" }, 
		{ 2, "loose-right" }, 
		{ 2, "straight" }, 
		{ 3, "straight" }, 
		{ 2, "straight" }
	};

	for(auto it = drag_master.begin(); it != drag_master.end(); ++it) {
		_race_track->addToLayout(*it);
	}
}