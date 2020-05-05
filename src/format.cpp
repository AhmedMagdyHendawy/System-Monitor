#include <string>

#include "format.h"

using std::string;
using std::to_string;
// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    int hour = seconds/3600;
	seconds = seconds%3600;
	int min = seconds/60;
	seconds = seconds%60;
	int sec = seconds;
    return to_string(hour)+ ':'+to_string(min)+':'+to_string(sec);
 }