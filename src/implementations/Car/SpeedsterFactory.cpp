#include "SpeedsterFactory.h"

CarRefined * SpeedsterFactory::createCar(int lane) {
	return new Speedster(lane);
}
