#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "RaceTrack.h"
#include "RaceTrackBuilder.h"
#include "CornerMasterBuilder.h"
#include "DragMasterBuilder.h"
#include "CreateTrack.h"

class RaceTrackPrototypeFactory
{
private:
	std::map<std::string, RaceTrack *> _tracks;
	std::vector<std::string> _track_names;
public:
	RaceTrackPrototypeFactory();
	virtual ~RaceTrackPrototypeFactory() {};
	std::vector<std::string> getNames();

	RaceTrack * createRaceTrack(const std::string &);
};

