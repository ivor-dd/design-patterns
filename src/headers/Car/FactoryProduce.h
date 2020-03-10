#pragma once

#include <string>

#include "CarAbstractFactory.h"
#include "SpeedsterFactory.h"
#include "ClassicFactory.h"
#include "RocketFactory.h"

class FactoryProduce
{
public:
	CarAbstractFactory * getFactory(const std::string &) const;
};