#include "RocketFactory.h"

CarRefined * RocketFactory::createCar(int lane) {
	return new Rocket(lane);
}
