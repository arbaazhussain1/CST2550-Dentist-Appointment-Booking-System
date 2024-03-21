#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include <iostream>

template <typename T> T print(T message) {
  std::cout << message;
  return message;
}

template <typename T> T println(T message) {
  std::cout << message << "\n";
  return message;
}

#endif
