#include "CreateTrack.h"

RaceTrack * CreateTrack::generateTrack(RaceTrackBuilder * rtb) {
	_race_track_builder = rtb;
	_race_track_builder->createRaceTrack();
	_race_track_builder->createName();
	_race_track_builder->makeLayout();
	return _race_track_builder->getRaceTrack();
}
