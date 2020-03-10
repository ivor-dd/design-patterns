#pragma once

#include <vector>
#include <string>

#include "RaceTrack.h"
#include "RaceTrackBuilder.h"

class CornerMasterBuilder : public RaceTrackBuilder
{
public:
	virtual ~CornerMasterBuilder() {};

	virtual void createName() override;
	virtual void makeLayout() override;
};