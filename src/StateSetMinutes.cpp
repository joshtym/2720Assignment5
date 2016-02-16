// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * StateSetMinutes Implementation
 * Professor: Robert  Benkoczi
 * Program Name: StateSetMinutes.cpp
 * Software Used: Geany
*/
#include "StateSetMinutes.h"
#include "StateShowTime.h"

StateInterface* StateSetMinutes::nextState()
{
	// Delete itself and return new state
	this->deleteItself();
	return new StateShowTime();
}

void StateSetMinutes::deleteItself()
{
	delete this;
}

void StateSetMinutes::incrementValue(std::string& currentAlarm)
{
	// Divide up the string into its respective hour and minute portions
	std::string hours = currentAlarm.substr(0, 2);
	std::string minutes = currentAlarm.substr(3, 2);
	
	// Convert string into a usuable ints and increment
	int convertedIntMinutes = stoi(minutes);
	int convertedIntHours = stoi(hours);
	convertedIntMinutes++;
	
	// Check that we haven't reached the end of the hour. If so,
	// increment hour and return minutes back to 0
	if (convertedIntMinutes > 59)
	{
		convertedIntMinutes = convertedIntMinutes % 60;
		convertedIntHours++;
		convertedIntHours = convertedIntHours % 24;
	}
	
	// Convert back into usuable string and recreate alarm string
	minutes = convertValueToString(convertedIntMinutes);
	hours = convertValueToString(convertedIntHours);
	currentAlarm = hours + ":" + minutes;
}

void StateSetMinutes::decrementValue(std::string& currentAlarm)
{
	// Divide up the string into its respective hour and minute portions
	std::string hours = currentAlarm.substr(0, 2);
	std::string minutes = currentAlarm.substr(3, 2);
	
	// Convert string into a usuable ints and decrement
	int convertedIntMinutes = stoi(minutes);
	int convertedIntHours = stoi(hours);
	convertedIntMinutes--;
	
	// Check that we haven't looped around. If so, decrement hour and
	// set minutes to 59
	if (convertedIntMinutes < 0)
	{
		convertedIntMinutes = 59;
		convertedIntHours--;
		
		if (convertedIntHours < 0)
			convertedIntHours = 23;
	}
	
	// Convert back into usuable string and recreate alarm string
	minutes = convertValueToString(convertedIntMinutes);
	hours = convertValueToString(convertedIntHours);
	currentAlarm = hours + ":" + minutes;
}

std::string StateSetMinutes::convertValueToString(int givenValue)
{	
	// Variable Declaration
	std::string convertedValue;
	
	// Convert into usuable string and return
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
