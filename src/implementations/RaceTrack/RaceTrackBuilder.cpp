#include "RaceTrackBuilder.h"

void RaceTrackBuilder::createRaceTrack() {
	_race_track = std::make_unique<RaceTrack>();
}

RaceTrack * RaceTrackBuilder::getRaceTrack() {
	return _race_track.release();
}

