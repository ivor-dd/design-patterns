#pragma once

#include <vector>
#include <tuple>
#include <string>

class RaceTrack
{
protected:
	int _length;
	std::vector<std::tuple<int, std::string>> _layout;
	std::string _name;
	std::string _weather;
public:
	RaceTrack();

	void setName(const std::string &);
	void setWeather(const std::string &);
	void addToLayout(const std::tuple<int, std::string> &);

	int getLength() const;
	std::string getName() const;
	std::string getWeather() const;
	std::tuple<int, std::string> getFromLayout(const int) const;
};