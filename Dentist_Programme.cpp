#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Print_Functions.h"
#include "Input_Validation.h"

int main() {

  std::string testString = "";

  std::cout << "Test 1." << std::endl;
  print("Test 2. \n");
  print("Test 3. \n");
  print("Test 4. ");
  println("Test 5.");
  println("Test 6.");
  print(1);

  println(testString);

//  if (isEmpty(testString)) {
//    println("True.");
//  }
//
//  testString = "1";

//  if (!isEmpty(testString)) {
//    println("False.");
//  }
//
//  if (isIntegerString(testString)) {
//    println("True.");
//  }

//  testString = "-1";

//  if (isIntegerString(testString)) {
//    println("True.");
//  }
//
//  testString = "Test.";
//
//  if (!isIntegerString(testString)) {
//    println("False.");
//  }
//
}
