#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include <iostream> // Include necessary header for input and output operations

// Function template to print a message without a newline
template <typename T> T print(T message) {
  std::cout << message; // Output the message without a newline
  return message; // Return the message
}

// Function template to print a message with a newline
template <typename T> T println(T message) {
  std::cout << message << "\n"; // Output the message with a newline
  return message; // Return the message
}

#endif // PRINT_FUNCTIONS_H
