#include "ClassicFactory.h"

CarRefined * ClassicFactory::createCar(int lane) {
	return new Classic(lane);
}
