#include <iostream>
#include "Calendar.h"
#include "Print_Functions.h"

std::string Calendar::printTime(struct tm time) {

  std::string output = "";

  output = std::to_string(time.tm_mday) + "/" + std::to_string(time.tm_mon + 1) + "/" + std::to_string(time.tm_year + 1900);

  return output;
  
}

void Calendar::printDate() {

  long int displayDate = 0;
  struct tm displayDateTime;
  std::string daysFromTodayInput = "";
  int daysFromToday = 0;
  std::cin  >> daysFromTodayInput;
  bool inputError = false;

  if (daysFromTodayInput == "") {
    println("Enter the number of days.");
    printDate();
  }

  if (daysFromTodayInput[0] == '-') {
    for (unsigned short int i = 1; i < daysFromTodayInput.length(); i++) {
      if (!isdigit(daysFromTodayInput[i])) {
	inputError = true;
      }
    }
  } else {
    for (unsigned short int i = 0; i < daysFromTodayInput.length(); i++) {
      if (!isdigit(daysFromTodayInput[i])) {
	inputError = true;
      }
    }
  }

  if (inputError) {
    println("Invalid input. Only integers may be used.");
    printDate();
  } else {
    daysFromToday = stoi(daysFromTodayInput);
    currentTime = time(NULL);
    presentTime=*localtime(&currentTime);
    displayDate = currentTime + (day * daysFromToday);
    displayDateTime=*localtime(&displayDate);

    if (daysFromToday == 0) {
      print("Today is: ");
      println(printTime(presentTime));
    } else if (daysFromToday == -1) {
      print("Yesterday is: ");
      println(printTime(displayDateTime));
    } else if (daysFromToday == 1) {
      print("Tomorrow is: ");
      println(printTime(displayDateTime));
    } else if (daysFromToday < 0) {
      print((daysFromToday * -1));
      print(" days before today is: ");
      println(printTime(displayDateTime));
    } else if (daysFromToday > 0) {
      print(daysFromToday);
      print(" days after today is: ");
      println(printTime(displayDateTime));
    }

    println("Enter command.");
  }

}
