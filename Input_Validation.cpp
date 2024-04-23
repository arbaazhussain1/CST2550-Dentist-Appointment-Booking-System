#include "Input_Validation.h"

bool isEmpty(const std::string& input) {
  if (input == "") {
    return true;
  } else {
    return false;
  }
}

bool isIntegerString(const std::string& input) {
  
  bool result = true;
  
  if (input[0] == '-' && input.length() > 1) {
    for (unsigned short int i = 1; i < input.length(); i++) {
      if (!isdigit(input[i])) {
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
  
  return result;
  
}
