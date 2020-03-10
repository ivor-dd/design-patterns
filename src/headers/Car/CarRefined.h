#pragma once

#include <string>

#include "Car.h"
#include "Racer.h"

class CarRefined : public Car
{
protected:
	Racer * _driver_type;
	int _speed;
	int _position;
	int _lane;
	double _damage;

public:
	CarRefined(std::string, double, double, double, double, int);
	virtual ~CarRefined();

	void setDriverType(Racer *);
	void updatePosition();

	Racer * getDriverType();
	int getPosition();
	int getLane();

	void accelerate() override;
	void deccelerate() override;
	void left() override;
	void right() override;

	void collision();
};