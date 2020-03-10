#include "RaceTrackPrototypeFactory.h"

RaceTrackPrototypeFactory::RaceTrackPrototypeFactory() {
	CreateTrack track_maker;
	CornerMasterBuilder corner_master;
	DragMasterBuilder drag_master;

	_tracks["Corner Master"] = track_maker.generateTrack(&corner_master);
	_tracks["Drag Master"] = track_maker.generateTrack(&drag_master);

	for (auto it = _tracks.begin(); it != _tracks.end(); ++it) {
		_track_names.push_back(it->second->getName());
	}	
}

RaceTrack * RaceTrackPrototypeFactory::createRaceTrack(const std::string & chosen_track) {
	return new RaceTrack(*_tracks[chosen_track]);
}

std::vector<std::string> RaceTrackPrototypeFactory::getNames() {
	return _track_names;
}