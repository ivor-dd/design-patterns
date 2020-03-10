#include "GameState.h"

GameState::GameState() : _current_track(nullptr){}

GameState * GameState::getInstace() {
	if(_instance == nullptr) 
		_instance = new GameState();
	return _instance;
}

void GameState::setCurrentTrack(RaceTrack * current_track) {
	_current_track = current_track;
}

void GameState::setNumParticipants(const std::string & n) {
	_num_participants = std::stoi(n);
}

void GameState::addFactory(const std::string & name, CarAbstractFactory * factory) {
	_available_cars.push_back(name);
	_name_factory.insert({ name, factory });
}

void GameState::addParticipant(Racer * driver, const std::string & name, const int lane) {
	CarRefined * register_participant = _name_factory[name]->createCar(lane);
	register_participant->setDriverType(driver);
	_participants.push_back(register_participant);
}

void GameState::fullParticipants() {
	std::mt19937 generator(_device());
	std::uniform_int_distribution<> dis(0, _available_cars.size() - 1);
	int number_of_starting_lanes = std::get<0>(_current_track->getFromLayout(0));
	int j = 2;
	for (auto i = 1; i < _num_participants; ++i) {
		NPC * character = new NPC;
		addParticipant(character, _available_cars[dis(generator)], j);
		if (j == number_of_starting_lanes) {
			j = 1;
		} else {
			++j;
		}
	}
}

RaceTrack * GameState::getCurrentTrack() const {
	return _current_track;
}

int GameState::getNumParticipants() const {
	return _num_participants;
}

std::vector<std::string> GameState::getCarNames() {
	return _available_cars;
}

CarRefined * GameState::getParticipant(int i) {
	return _participants[i];
}

void GameState::applyWeather() {
	std::mt19937 generator(_device());
	std::uniform_int_distribution<> dis(0, _weather_types.size() - 1);
	_current_track->setWeather(_weather_types[dis(generator)]);
}

void GameState::restart() {
	delete _current_track;
	_current_track = nullptr;

	for (auto it = _name_factory.begin(); it != _name_factory.end(); ++it) {
		delete it->second;
		it->second = nullptr;
	}

	for (auto it = _participants.begin(); it != _participants.end(); ++it) {
		delete *it;
		*it = nullptr;
	}
}