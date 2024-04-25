#ifndef CALENDAR_H
#define CALENDAR_H

#include <ctime> // Include the header file for time-related functions

class Calendar {
 private:
  time_t currentTime; // Variable to store the current time
  struct tm presentTime; // Struct to store the current date and time components
  const int day = 86400;  // Number of seconds in a day (24 hours)
 public:
  std::string printTime(struct tm tim);  // Function declaration to print formatted time
  void printDate(); // Function declaration to print date based on user input
};

#endif  // CALENDAR_H
