#pragma once

#include "CarRefined.h"

class Action
{
public:
	virtual ~Action();
	virtual void execute() = 0;
};