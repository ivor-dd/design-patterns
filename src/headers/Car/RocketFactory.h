#pragma once

#include "CarAbstractFactory.h"
#include "Rocket.h"

class RocketFactory : public CarAbstractFactory
{
public:
	CarRefined * createCar(int) override;
};