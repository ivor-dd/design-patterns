DamagedCar::DamagedCar(std::string name, double top_speed, double acceleration, double breaking, double handling) 
	: Car(0, 0, 0, 0, 0) {}

void DamagedCar::accelerate() {
	std::cout << "Car is wrecked";
}

void DamagedCar::deccelerate() {
	std::cout << "Car is wrecked";
}

void DamagedCar::left() {
	std::cout << "It won't start";
}

void DamagedCar::right() {
	std::cout << "It won't start";
}