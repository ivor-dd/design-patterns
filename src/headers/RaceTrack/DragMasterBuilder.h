#pragma once

#include <vector>
#include <string>

#include "RaceTrack.h"
#include "RaceTrackBuilder.h"

class DragMasterBuilder : public RaceTrackBuilder
{
public:
	virtual ~DragMasterBuilder() {};

	virtual void createName() override;
	virtual void makeLayout() override;
};