#pragma once

#include "CarAbstractFactory.h"
#include "Classic.h"

class ClassicFactory : public CarAbstractFactory
{
public:
	CarRefined * createCar(int) override;
};