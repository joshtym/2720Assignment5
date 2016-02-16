// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * StateSetHour Interface
 * Professor: Robert  Benkoczi
 * Program Name: StateSetHour.h
 * Software Used: Geany
*/
#ifndef STATESETHOUR_H
#define STATESETHOUR_H

#include "StateInterface.h"

/// State which allows for manipulation of the hour value of the alarm
class StateSetHour : public StateInterface
{
	public:
		/// Function that moves the StateInterface onto the next state
		/**
		 * Once called, this will delete itself and return a new State
		 * of the next appropiate value
		**/
		StateInterface* nextState();
		
		/// Function to increment the value of the given hours
		/// string
		/**
		 * Takes the string value, breaks it into an int, and increments
		 * the value of the hour portion
		**/
		void incrementValue(std::string&);
		
		/// Function to decrement the value of the given hours
		/// string
		/**
		 * Takes the string value, breaks it into an int, and decrements
		 * the value of the hours portion
		**/
		void decrementValue(std::string&);
		
	protected:
		/// Protected helper function to allow for easy conversion from
		/// int to string
		std::string convertValueToString(int);
		
		/// Protected function to help in deletion of allocated memory
		void deleteItself();
};
#endif
