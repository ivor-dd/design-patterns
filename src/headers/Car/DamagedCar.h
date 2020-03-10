#pragma once

#include <string>

#include "Car.h"
#include "Racer.h"


class DamagedCar : public Car
{
protected:
	Racer * _driver_type;

public:
	DamagedCar();
	virtual ~DamagedCar() {};

	void accelerate() override;
	void deccelerate() override;
	void left() override;
	void right() override;
};