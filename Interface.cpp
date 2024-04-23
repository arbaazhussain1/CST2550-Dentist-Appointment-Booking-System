#include <iostream>
#include "Interface.h"
#include "Print_Functions.h"
#include "View.h"
#include "Data.h"
#include "Book.h"

void mainMenu();
void displayMenu();
void bookMenu();

void Interface::printMenu(short int menu) {
  for (long unsigned int i = 0; i < sizeof(menuOptions[menu]) / sizeof(std::string); i++) {
    if (menuOptions[menu][i] != "") {
      println(menuOptions[menu][i]);
    } else {
      break;
    }
  }
}

void Interface::mainMenu() {
  
  std::cin  >> userInput;

   if (userInput == "Display" || userInput == "display" || userInput == "1") {
    userInput = "";
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1);
    displayMenu();
  } else if (userInput == "Book" || userInput == "book" || userInput == "2") {
    userInput = "";
    book.startBookingProcess();
    printMenu(0);
    mainMenu();
  } else if (userInput == "Date" || userInput == "date" || userInput == "3") {
    userInput = "";
    println("Enter date to display (in days from today).");
    calendar.printDate();
    printMenu(0);
    mainMenu();
  } else if (userInput == "Add" || userInput == "add" || userInput == "4") {
    userInput = "";
    patientManager->addNewPatient();
    printMenu(0);
    mainMenu();
  } else if (userInput == "Exit" || userInput == "exit" || userInput == "5") {
    userInput = "";
    println("Exiting programme.");
    exit(0);
  } else {
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    mainMenu();
   }
   
}

void Interface::displayMenu() {
  
  std::cin  >> userInput;

   if (userInput == "Dentist" || userInput == "dentist" || userInput == "1") {
    userInput = "";
    view.printDentists();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1);
    displayMenu();
  } else if (userInput == "Patient" || userInput == "patient" || userInput == "2") {
    userInput = "";
    view.printPatients();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1);
    displayMenu();
  } else if (userInput == "Appointment" || userInput == "appointment" || userInput == "3") {
    userInput = "";
    view.printAppointments();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1);
    displayMenu();
  } else if (userInput == "Room" || userInput == "room" || userInput == "4") {
    userInput = "";
    view.printRooms();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1);
    displayMenu();
  } else if (userInput == "Return" || userInput == "return" || userInput == "5") {
    userInput = "";
    printMenu(0);
    mainMenu();
  } else {
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    displayMenu();
  }
   
}

void Interface::bookMenu() {
  
  std::cin  >> userInput;

   if (userInput == "Display" || userInput == "display" || userInput == "1") {
    userInput = "";
    println("Select class to display (dentists, patients, appointments or rooms).");
  } else if (userInput == "Book" || userInput == "book" || userInput == "2") {
    userInput = "";
    book.startBookingProcess();
  } else if (userInput == "Date" || userInput == "date" || userInput == "3") {
    userInput = "";
    println("Enter date to display (in days from today).");
  } else if (userInput == "Exit" || userInput == "exit" || userInput == "4") {
    userInput = "";
    println("Exiting programme.");
    exit(0);
  } else {
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    bookMenu();
  }
   
}
