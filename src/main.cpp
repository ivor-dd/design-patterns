#include <iostream>
#include <string>
#include <vector>

#include "algorithms/Array.h"
#include "algorithms/SquareMatrix.h"

#include "GameState.h"
#include "RaceTrack.h"
#include "RaceTrackPrototypeFactory.h"
#include "Car.h"
#include "CarAbstractFactory.h"
#include "FactoryProduce.h"

#include "Racer.h"
#include "Player.h"
#include "NPC.h"

GameState * GameState::_instance = nullptr;

int main() {
	/*
	Implements the [[singleton]] design pattern. We need a global class
	to control the state of the game.
	1. There is only one instance of this class
	2. Global access
	The class should abide to a
	1. A static instance
	2. A static get (for the instance)
	3. A private constructor
	*/

	GameState * state = GameState::getInstace();

	std::cout << 
	"		Welcome to Crash Test, the text car racing game!\n" <<
	"Remember to draft behind your oppents and avoid crashing into them if you can\n" <<
	"	Oh and type quickly... time is a factor, after all this is racing.\n\n";

	// This method is nested in the below prototype method
	/*
	Implements the [[builder]] design pattern. We need to create several
	complex objects.
	1. A builder is passed to a creater.
	2. The creator runs the builders methods
	3. The builder returns the objects instance
	*/
	/*
	Implements the [[prototype]] design pattern. It is expensive to create
	objects and they do not differ apart from weather.
	1. Object instances are created and placed in an unordered map.
	2. Deep copies of these objects are returned by the factory.
	*/
	
	RaceTrackPrototypeFactory prototypes;

	std::vector<std::string> available_tracks = prototypes.getNames();

	for(auto i = 1; i <= available_tracks.size(); ++i) {
		std::cout << i << ": " << available_tracks[i-1] << "\n";
	}

	std::string track;
	std::cout << "\nPlease select a track (Give the name): ";
	std::getline(std::cin, track);

	while(!(std::find(available_tracks.begin(), available_tracks.end(), track) != available_tracks.end())) {
		std::cout << "Thats not a track, check your spelling\n" <<
		"Please select a track: ";
		std::getline(std::cin, track);
	}
	
	state->setCurrentTrack(prototypes.createRaceTrack(track));
	state->applyWeather();

	/*
	Implements the [[Abstract Factory]] design pattern. Which may or may not
	have virtual methods associated with a base class.
	1. A producer produces a factory.
	2. A factory produces a object instance
	*/

	FactoryProduce factories;
	CarAbstractFactory * speedster_factory = factories.getFactory("Speedster");
	CarAbstractFactory * classic_factory = factories.getFactory("Classic");
	CarAbstractFactory * rocket_factory = factories.getFactory("Rocket");

	state->addFactory("Speedster", speedster_factory);
	state->addFactory("Classic", classic_factory);
	state->addFactory("Rocket", rocket_factory);

	std::string number_of_players;
	std::cout << "\nPlease select the number of players (including yourself)" <<
	"\nI didnt hadle this error so please make sure its an int: ";
	std::getline(std::cin, number_of_players);
	std::cout << "\n";

	state->setNumParticipants(number_of_players);

	/*
	Implements the [[Bridge]] design pattern. Decouples Racer and Car.
	Otherwise sublasses would need to be created for car where one belongs
	to the User and the other are NPC.
	1. An interface (Car).
	2. An implementation (Racer)
	3. A bridge, a refined abstraction of car.
	*/

	std::vector<std::string> available_cars = state->getCarNames();
	for(auto i = 1; i <= available_cars.size(); ++i) {
		std::cout << i << ": " << available_cars[i-1] << "\n";
	}

	std::string player_car;
	std::cout << "\nPlease select a car (Give the name): ";
	std::getline(std::cin, player_car);

	while(!(std::find(available_cars.begin(), available_cars.end(), player_car) != available_tracks.end())) {
		std::cout << "Thats not a car, check your spelling\n" <<
		"Please select a car: ";
		std::getline(std::cin, player_car);
	}

	Player * player_1 = new Player;

	state->addParticipant(player_1, player_car, 1);
	state->fullParticipants();

	while(state->getParticipant(0)->getPosition() < state->getCurrentTrack()->getLength()) {
		//std::cout << state->getParticipant(0)->getPosition() << "\n";
		//std::cout << state->getParticipant(0)->getLane() << "\n";
		state->getParticipant(0)->updatePosition();
		/* TODO:
		Finish Command Pattern for action
		Decoupling driving from the car

		Create observerable interface for RaceTrack
		Create observer interface for Refined car
		Use this  to determine distance from barriers and lanes

		Create State Class for refined car and love things like
		location, lane, damage and speed into this.

		Use mediator pattern to verify collisions between two cars
		Cars sends state to mediator
		if (Car1->location == Car2->location) {
			if (Car1->speed = car2->speed >>>) {
				car1->damage += alot
				car2->damage += alot
			} else {
				car1->damage += not so much
				car2->damage += not so much
			}
		}

		Use a chain of responsibility to verify collisions
		Class Handler
		Class sort and sweep
		Class
	
		Make a AI for other cars
		Create stratergy interface
		class Aggressive : public StrategyInterface
		class Defensive : public StrategyInterface
		Let the context be part of the NPC class

		...The list goes on
		*/
	}

	state->restart();

	return 0;
}
