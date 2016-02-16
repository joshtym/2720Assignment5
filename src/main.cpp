// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #5
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: main.cpp
 * Software Used: Geany
*/
#include "Clock.h"
#include <ncurses.h>

int main()
{
	// Variable declartion of the object
	Clock testClock;
	
	// Initialization of the ncurses library
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	
	// Create GUI within the terminal
	mvprintw(8,12,"Hit the q key to quit");
	mvprintw(10,0, "'TAB' - Iterates through modes on clock");
	mvprintw(11,0, "'+'   - Increments alarm value (hours/minutes) by 1");
	mvprintw(12,0, "'-'   - Decrements alarm value (hours/minutes) by 1"); 
	mvprintw(1, 6, "   Currently viewing the time       ", 0, "time");
	mvprintw(4,20, testClock.display().c_str(), 0 , "TAB");
	
	// Get next char
	int ch = getch();
	
	while (ch != ERR && ch != 'Q' && ch != 'q')
	{
		// If this key, then increment the alarm time. Note that the
		// incrementation is based on whether it's editing hours or
		// minutes. If viewing time, this does nothing
		if (ch == '+')
		{
			testClock.inc();
			testClock.display();
			mvprintw(4,20, testClock.display().c_str(), 0, "+");
		}
		// If this key, then decrement the alarm time. Note that the
		// decrementation is based on whether it's editing hours or
		// minutes. If viewing time, this does nothing
		else if (ch == '-')
		{
			testClock.dec();
			mvprintw(4,20, testClock.display().c_str(), 0, "-");
		}
		// If this key, iterate through the modes
		else if (ch == '\t')
		{
			testClock.mode();
			if (testClock.currentState() == 0)
				mvprintw(1, 6, "   Currently viewing the time       ", 0, "time");
			else if (testClock.currentState() == 1)
				mvprintw(1,6, " Currently editing the alarm's hour ", 0, "hour");
			else
				mvprintw(1,6, "Currently editing the alarm's minute", 0, "minute");
			mvprintw(4,20, testClock.display().c_str(), 0, "TAB");
		}
		refresh();
		ch = getchar();
	}
	
	endwin();
	
	return 0;
}
