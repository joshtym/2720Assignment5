// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * State Interface
 * Professor: Robert  Benkoczi
 * Program Name: StateInterface.h
 * Software Used: Geany
*/
#ifndef STATEINTERFACE_H
#define STATEINTERFACE_H

#include <string>

/// Interface from which all children will pull their functions from
class StateInterface
{
	public:
		~StateInterface() {}
		/// Virtual functions for the children. Their descriptions are
		/// defined in the child classes
		virtual StateInterface* nextState() = 0;
		virtual void incrementValue(std::string&) = 0;
		virtual void decrementValue(std::string&) = 0;
	
	protected:
		virtual std::string convertValueToString(int) = 0;
		virtual void deleteItself() = 0;
};
#endif
