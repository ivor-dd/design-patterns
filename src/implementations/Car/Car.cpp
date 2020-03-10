#include "Car.h"

Car::Car(std::string name, double top_speed, double acceleration, double breaking, double handling) : _name(name), _top_speed(top_speed), _acceleration(acceleration), _breaking(breaking), _handling(handling){}

std::string Car::getName() {
	return _name;
}

double Car::getTopSpeed() {
	return _top_speed;
}

double Car::getAcceleration() {
	return _acceleration;
}

double Car::getBreaking() {
	return _breaking;
}

double Car::getHandling() {
	return _handling;
}