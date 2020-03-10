#pragma once

#include "CarRefined.h"

class CarAbstractFactory 
{
public:
	virtual ~CarAbstractFactory() {};
	virtual CarRefined * createCar(int) = 0;
};

