#pragma once

#include "CarAbstractFactory.h"
#include "Speedster.h"

class SpeedsterFactory : public CarAbstractFactory
{
public:
	CarRefined * createCar(int) override;
};