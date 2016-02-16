// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * StateShowTime Implementation
 * Professor: Robert  Benkoczi
 * Program Name: StateShowTime.cpp
 * Software Used: Geany
*/
#include "StateShowTime.h"
#include "StateSetHour.h"

StateInterface* StateShowTime::nextState()
{
	// Delete itself and return a new state
	this->deleteItself();
	return new StateSetHour();
}

void StateShowTime::deleteItself()
{
	delete this;
}

void StateShowTime::incrementValue(std::string& currentAlarm)
{
}

void StateShowTime::decrementValue(std::string& currentAlarm)
{
}

std::string StateShowTime::convertValueToString(int)
{
}
