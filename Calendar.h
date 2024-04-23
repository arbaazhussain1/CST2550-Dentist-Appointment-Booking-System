#ifndef CALENDAR_H
#define CALENDAR_H

#include <ctime>

class Calendar {
 private:
  time_t currentTime;
  struct tm presentTime;
  const int day = 86400;
 public:
  std::string printTime(struct tm tim);
  void printDate();
};

#endif
