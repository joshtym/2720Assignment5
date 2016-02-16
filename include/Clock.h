// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * Clock Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Clock.h
 * Software Used: Geany
*/
#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include "StateInterface.h"

// Binds the definition of StateInterface* to the keyword State
typedef StateInterface* State;

/// Class for a rudimentary clock. Includes an element to display the
/// time, as well as an alarm clock. The alarm clock can be configured
/// In both the hours and the minutes but incrementing or decrementing
/// the values
class Clock
{
	private:
		// Private data members depicting the elements of the clock
		State state;
		int currentStateNumber;
		std::string currentTime;
		std::string alarmTime;
		
		/// Helper function that allows conversion of int to string
		/**
		 * \return the string from the converted integer. Used to
		 * convert the randomized minutes and hours into the string
		 * appropiate format
		**/
		std::string convertIntToClockString(int);
		
	public:
		Clock();
		~Clock();
		/// Called when mode key is pressed
		void mode();
		
		/// Called when the + key is pressed
		void inc();
		
		/// Caled when the - key is pressed
		void dec();
		
		/// The display function
		/**
		 * \return a string representing what is currently displayed
		 * by the clock
		**/
		std::string display();
		
		/// Function that allows others calling this object to know
		/// what state it is in
		/**
		 * \return an integer representing the current state. 0 equates
		 * to the time being shown. 1 equates to hour editing mode. 2
		 * equates to minute editing mode of alarm clock.
		**/
		int currentState();
};
#endif
