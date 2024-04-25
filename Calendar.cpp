// Include necessary  files:
#include <iostream>
#include "Calendar.h" // Include the header file for the Calendar class
#include "Print_Functions.h" // Include the header file for print functions

// Function to format and print time
std::string Calendar::printTime(struct tm time) {

  std::string output = "";

    // Format the time components into a string
    output = std::to_string(time.tm_mday) + "/" + std::to_string(time.tm_mon + 1) + "/" + std::to_string(time.tm_year + 1900);

  return output; // Return the formatted time string
  
}

// Function to print the date based on user input
void Calendar::printDate() {

  long int displayDate = 0;  // Variable to store the date to be displayed
  struct tm displayDateTime;  // Struct to store date and time components
  std::string daysFromTodayInput = ""; // User input for number of days from today
  int daysFromToday = 0; // Number of days from today
  std::cin  >> daysFromTodayInput; // Read user input
  bool inputError = false;  // Flag to track input errors

    // Check if user input is empty
    if (daysFromTodayInput == "") {
    println("Enter the number of days."); // Prompt user to enter the number of days
    printDate(); // Call the function recursively to get valid input
  }

    // Check if user input starts with a negative sign
  if (daysFromTodayInput[0] == '-') {
      // Iterate through the characters of the input string
      for (unsigned short int i = 1; i < daysFromTodayInput.length(); i++) {
          // Check if each character is a digit
          if (!isdigit(daysFromTodayInput[i])) {
	inputError = true; // Set inputError flag if non-digit character found
      }
    }
  } else {
      // Iterate through the characters of the input string
      for (unsigned short int i = 0; i < daysFromTodayInput.length(); i++) {
          // Check if each character is a digit
          if (!isdigit(daysFromTodayInput[i])) {
	inputError = true; // Set inputError flag if non-digit character found
      }
    }
  }
    // If inputError flag is set, print error message and prompt user to enter valid input
  if (inputError) {
    println("Invalid input. Only integers may be used.");
    printDate();
  } else {
      // Convert daysFromTodayInput to an integer
      daysFromToday = stoi(daysFromTodayInput);
      // Get the current time
      currentTime = time(NULL);
      // Get the current date and time components
      presentTime=*localtime(&currentTime);
      // Calculate the date to be displayed based on the user input
      displayDate = currentTime + (day * daysFromToday);
      // Get the date and time components for the display date
      displayDateTime=*localtime(&displayDate);

      // Print the date based on the number of days from today
      if (daysFromToday == 0) {
      print("Today is: ");
      println(printTime(presentTime)); // Print today's date
    } else if (daysFromToday == -1) {
      print("Yesterday is: ");
      println(printTime(displayDateTime)); // Print yesterday's date
    } else if (daysFromToday == 1) {
      print("Tomorrow is: ");
      println(printTime(displayDateTime)); // Print tomorrow's date
    } else if (daysFromToday < 0) {
      print((daysFromToday * -1));
      print(" days before today is: ");
      println(printTime(displayDateTime)); // Print date before today
    } else if (daysFromToday > 0) {
      print(daysFromToday);
      print(" days after today is: ");
      println(printTime(displayDateTime)); // Print date after today
    }

    println("Enter command."); // Prompt user to enter a command.
  }

}
