#include "FactoryProduce.h"

CarAbstractFactory * FactoryProduce::getFactory(const std::string & description) const {
	if (description == "Speedster") {
		return new SpeedsterFactory();
	} else if (description == "Classic") {
		return new ClassicFactory();
	} else {
		return new RocketFactory();
	}
}