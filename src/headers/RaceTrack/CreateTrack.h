#pragma once

#include <iostream>

#include "RaceTrack.h"
#include "RaceTrackBuilder.h"

class CreateTrack
{
protected:
	RaceTrackBuilder * _race_track_builder;
public:
	RaceTrack * generateTrack(RaceTrackBuilder *);
};