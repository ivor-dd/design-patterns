#pragma once

#include <vector>
#include <string>
#include <memory>

#include "RaceTrack.h"

class RaceTrackBuilder
{
protected:
	std::unique_ptr<RaceTrack> _race_track;
public:
	virtual ~RaceTrackBuilder() {};

	void createRaceTrack();
	RaceTrack * getRaceTrack();

	virtual void createName() = 0;
	virtual void makeLayout() = 0;
};