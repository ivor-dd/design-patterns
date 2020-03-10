#pragma once

#include "CarRefined.h"
#include "Action.h"

class AccelerateLeft : public Action
{
public:
	virtual ~Action();
	void execute(CarRefined &) override;
};