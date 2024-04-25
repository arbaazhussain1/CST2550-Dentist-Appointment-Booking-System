#include "Input_Validation.h" // Include the header file defining input validation functions

// Function to check if a string is empty
bool isEmpty(const std::string& input) {
  if (input == "") {
    return true;
  } else {
    return false;
  }
}

// Function to check if a string represents an integer
bool isIntegerString(const std::string& input) {
  
  bool result = true;

    // Check if the string contains only digits or a negative sign at the beginning
    if (input[0] == '-' && input.length() > 1) {  // If the first character is '-', start from index 1
    for (unsigned short int i = 1; i < input.length(); i++) {
      if (!isdigit(input[i])) { // If any character is not a digit, it's not an integer
	result = false;
      }
    }
  } else {
    for (unsigned short int i = 0; i < input.length(); i++) {
      if (!isdigit(input[i])) {
	result = false;
      }
    }
  }
  
  return result;  // If all characters are digits (or '-' for negative integers), it's an integer string
  
}
