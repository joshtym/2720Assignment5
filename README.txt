======================================================================
*****************************Clock Simulator**************************
======================================================================
This program simulators the working of rudimentary clock that has
basic functions. It will have a current time and alarm time. The current
time can be display at any time. YOu can also alter the alarm time's
hours and minutes at any time by using the mode key to cycle into each
respective edit mode.

JUMP HERE FOR MEMORY LEAK
Note that after extenstive testing and research, the problem that lies
within the program is not within my code, but rather the ncurses library
and the current setup provided with the inital code for the assignment.
However, I do not believe the issue is with his code, but rather with
the library itself. I've found that it's approximating 390 blocks that
are not being freed at the during the program. Note that running without
a clock object will initialize a value similar to this
