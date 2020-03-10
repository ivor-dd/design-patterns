#pragma once

#include <string>

class Car
{
protected:
	std::string _name;
	double _top_speed;
	double _acceleration;
	double _breaking;
	double _handling;
public:
	Car(std::string, double, double, double, double);
	virtual ~Car() {};

	std::string getName();
	double getTopSpeed();
	double getAcceleration();
	double getBreaking();
	double getHandling();

	virtual void accelerate() = 0;
	virtual void deccelerate() = 0;
	virtual void left() = 0;
	virtual void right() = 0;
};