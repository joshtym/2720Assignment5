// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * StateSetHour Implementation
 * Professor: Robert  Benkoczi
 * Program Name: StateSetHour.cpp
 * Software Used: Geany
*/
#include "StateSetHour.h"
#include "StateSetMinutes.h"

StateInterface* StateSetHour::nextState()
{
	// Delete itself and return a new State
	this->deleteItself();
	return new StateSetMinutes();
}

void StateSetHour::deleteItself()
{
	delete this;
}

void StateSetHour::incrementValue(std::string& currentAlarm)
{
	// Divide up the string into its respective hour and minute portions
	std::string hours = currentAlarm.substr(0, 2);
	std::string minutes = currentAlarm.substr(3, 2);
	
	// Convert string into a usuable int and increment
	int convertedIntHours = stoi(hours);
	convertedIntHours++;
	
	// Check to make sure we haven't reached the end of the day
	if (convertedIntHours > 23)
		convertedIntHours = 0;
	
	// Convert value back to string and recreate the alarm string
	hours = convertValueToString(convertedIntHours);
	currentAlarm = hours + ":" + minutes;
}

void StateSetHour::decrementValue(std::string& currentAlarm)
{
	// Divide up the string into its respective hour and minute portions
	std::string hours = currentAlarm.substr(0, 2);
	std::string minutes = currentAlarm.substr(3, 2);
	
	// Convert string into a usuable int and decrement
	int convertedIntHours = stoi(hours);
	convertedIntHours--;
	
	// Check to make sure we haven't looped around
	if (convertedIntHours < 0)
		convertedIntHours = 23;
	
	// Convert back to string and recreate alarm string
	hours = convertValueToString(convertedIntHours);
	currentAlarm = hours + ":" + minutes;
}

std::string StateSetHour::convertValueToString(int givenValue)
{
	// Variable Declaration
	std::string convertedValue;
	
	// Turn into usuable string and return
	switch (givenValue)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			convertedValue = "0";
			convertedValue.append(std::to_string(givenValue));
			break;
		default:
			convertedValue = std::to_string(givenValue);
			break;
	}
	return convertedValue;
}
