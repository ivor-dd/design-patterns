#include "CarRefined.h"

CarRefined::CarRefined(std::string name, double top_speed, double acceleration, double breaking, double handling, int lane) 
	: Car(name, top_speed, acceleration, breaking, handling), _position(0), _speed(0), _lane(lane), _damage(0) {}
	

CarRefined::~CarRefined() {
	delete _driver_type;
	_driver_type = nullptr;
}

void CarRefined::setDriverType(Racer * driver) {
	_driver_type = driver;
}

void CarRefined::updatePosition() {
	++_position;
}

Racer * CarRefined::getDriverType() {
	return _driver_type;
}

int CarRefined::getPosition() {
	return _position;
}

int CarRefined::getLane() {
	return _lane;
}

void CarRefined::accelerate() {
	double attempt = _speed + _acceleration;
	if (attempt > _top_speed) {
		_speed = _top_speed;
	} else {
		_speed = attempt;
	}
}

void CarRefined::deccelerate() {
	double attempt = _speed - _breaking;
	if (attempt < 0) {
		_speed = 0;
	} else {
		_speed = attempt;
	}
}

void CarRefined::left() {
	double attempt = _lane - 1;
	if (attempt < 1) {
		collision();
	} else {
		_lane = attempt;
	}
}

void CarRefined::right() {
	double attempt = _lane + 1;
	/*
	Just one reason why we need
	the observer interface
	if (attempt < 1) {
		collision()
	} else {
		_lane = attempt;
	}
	*/
}

void CarRefined::collision() {
	_damage += 0.2;
}