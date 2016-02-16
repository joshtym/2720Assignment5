// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * StateSetMinutes Interface
 * Professor: Robert  Benkoczi
 * Program Name: StateSetMinutes.h
 * Software Used: Geany
*/
#ifndef STATESHOWTIME_H
#define STATESHOWTIME_H

#include "StateInterface.h"

class StateShowTime : public StateInterface
{
	public:
		/// Function that moves the StateInterface onto the next state
		/**
		 * Once called, this will delete itself and return a new State
		 * of the next appropiate value
		**/
		StateInterface* nextState();
		
		/// Required functions from the Interface
		/**
		 * Note that in this current state, these functions will
		 * perform no action
		**/
		void incrementValue(std::string&);
		void decrementValue(std::string&);
		
	protected:
		/// Protected helper function to allow for easy conversion from
		/// int to string
		std::string convertValueToString(int);
		
		/// Protected function to help in deletion of allocated memory
		void deleteItself();
};
#endif
