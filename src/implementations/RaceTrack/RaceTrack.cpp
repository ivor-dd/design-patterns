#include "RaceTrack.h"

RaceTrack::RaceTrack() : _length(0), _layout({ }){}

int RaceTrack::getLength() const {
	return _length;
}

void RaceTrack::setName(const std::string & name) {
	_name = name;
}

void RaceTrack::setWeather(const std::string & weather) {
	_weather = weather;
}

void RaceTrack::addToLayout(const std::tuple<int, std::string> & route) {
	_layout.push_back(route);
	++_length;
}

std::string RaceTrack::getName() const {
	return _name;
}

std::string RaceTrack::getWeather() const {
	return _weather;
}

std::tuple<int, std::string> RaceTrack::getFromLayout(const int location) const {
	return _layout[location];
}
