// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * Clock Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Clock.cpp
 * Software Used: Geany
*/

#include "Clock.h"
#include "StateShowTime.h"
#include <cstdlib>
#include <ctime>

Clock::Clock()
{
	int minutes, hours;
	
	// Creates a randomized time
	srand(time(0)); 
	minutes = rand() % 60;
	hours = rand() % 24;
	
	// Initialize the initial state in the "Show time" state
	state = new StateShowTime();
	currentStateNumber = 0;
	currentTime = convertIntToClockString(hours) + ":" + convertIntToClockString(minutes);
	
	// Initializes the alarm to 12 am
	alarmTime = "00:00";
}

Clock::~Clock()
{
	// Delete allocated memory
	delete state;
}

void Clock::mode()
{
	// Iterate to the next mode and adjust the integer accordingly
	state = state->nextState();
	currentStateNumber++;
	currentStateNumber = currentStateNumber % 3;
}

void Clock::inc()
{
	// Increment the value. If not in show time mode, this will
	// run successfully, else, it will do nothing
	state->incrementValue(alarmTime);
}

void Clock::dec()
{
	// Decrement the value. If not in show time mode, this will
	// run successfully, else, it will do nothing
	state->decrementValue(alarmTime);
}

std::string Clock::display()
{
	// Show currentTime if it's in that mode, else, show alarm time
	if (currentStateNumber == 0)
		return currentTime;
	else
		return alarmTime;
}

std::string Clock::convertIntToClockString(int givenInput)
{
	std::string toBeReturned;
	
	// Converts the integer into an appropiate time format
	switch (givenInput)
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
			toBeReturned = "0";
			toBeReturned.append(std::to_string(givenInput));
			break;
		default:
			toBeReturned = std::to_string(givenInput);
	}
	
	return toBeReturned;
}

int Clock::currentState()
{
	return currentStateNumber;
}
