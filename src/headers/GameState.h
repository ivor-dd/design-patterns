#pragma once

#include <string>
#include <map>
#include <random>
#include <algorithm>

#include "RaceTrack.h"
#include "CarRefined.h"
#include "CarAbstractFactory.h"
#include "Racer.h"
#include "NPC.h"

class GameState
{
private:
	GameState();
	static GameState * _instance;
	std::random_device _device;

	std::vector<std::string> _weather_types = { "sunny", "rainy" };
	RaceTrack * _current_track;

	std::vector<std::string> _available_cars;
	std::map<std::string, CarAbstractFactory *> _name_factory;

	int _num_participants;
	std::vector<CarRefined *> _participants;

public:
	static GameState * getInstace();

	void setCurrentTrack(RaceTrack *);
	void setNumParticipants(const std::string &);
	void addFactory(const std::string &, CarAbstractFactory *);
	void addParticipant(Racer *, const std::string &, const int);
	void fullParticipants();

	RaceTrack * getCurrentTrack() const;
	int getNumParticipants() const;
	std::vector<std::string> getCarNames();	
	CarRefined * getParticipant(int);

	void applyWeather();

	void restart();
};