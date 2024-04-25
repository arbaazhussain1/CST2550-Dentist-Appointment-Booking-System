#include <iostream>
#include "Interface.h"
#include "Print_Functions.h"
#include "View.h"
#include "Data.h"
#include "Book.h"

// Define mainMenu, displayMenu, and bookMenu as global functions.
void mainMenu();
void displayMenu();
void bookMenu();

// Implementation of printMenu method in Interface class.
void Interface::printMenu(short int menu) {
    // Loop through menu options and print them until an empty string is encountered.
    for (long unsigned int i = 0; i < sizeof(menuOptions[menu]) / sizeof(std::string); i++) {
    if (menuOptions[menu][i] != "") {
      println(menuOptions[menu][i]); // Print menu option.
    } else {
      break; // Exit loop if an empty string is encountered.
    }
  }
}

// Implementation of mainMenu method in Interface class.
void Interface::mainMenu() {
  
  std::cin  >> userInput; // Get user input.
    // Handle user input for different menu options.
   if (userInput == "Display" || userInput == "display" || userInput == "1") {
   // Display submenu for viewing data.
   userInput = "";
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1); // Print submenu options.
    displayMenu(); // Proceed to display menu.
  } else if (userInput == "Book" || userInput == "book" || userInput == "2") {
    // Initiate booking process.
    userInput = "";
    book.startBookingProcess();
    printMenu(0);  // Print main menu options.
    mainMenu(); // Return to main menu.
  } else if (userInput == "Date" || userInput == "date" || userInput == "3") {
    // Display date.
    userInput = "";
    println("Enter date to display (in days from today).");
    calendar.printDate(); // Print date.
    printMenu(0); // Print main menu options.
    mainMenu(); // Return to main menu.
  } else if (userInput == "Add" || userInput == "add" || userInput == "4") {
    // Add new patient.
    userInput = "";
    patientManager->addNewPatient();
    printMenu(0);  // Print main menu options.
    mainMenu(); // Return to main menu.
  } else if (userInput == "Exit" || userInput == "exit" || userInput == "5") {
    // Exit program.
    userInput = "";
    println("Exiting programme.");
    exit(0); // Terminate program.
  } else {
    // Handle invalid input.
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    mainMenu(); // Return to main menu.
   }
   
}

// Implementation of displayMenu method in Interface class.
void Interface::displayMenu() {
  
  std::cin  >> userInput; // Get user input.

    // Handle user input for different display options.
    if (userInput == "Dentist" || userInput == "dentist" || userInput == "1") {
    // Display dentists.
    userInput = "";
    view.printDentists();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1); // Print submenu options.
    displayMenu(); // Return to display menu.
  } else if (userInput == "Patient" || userInput == "patient" || userInput == "2") {
    // Display patients.
    userInput = "";
    view.printPatients();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1); // Print submenu options.
    displayMenu(); // Return to display menu.
  } else if (userInput == "Appointment" || userInput == "appointment" || userInput == "3") {
    // Display appointments.
    userInput = "";
    view.printAppointments();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1); // Print submenu options.
    displayMenu(); // Return to display menu.
  } else if (userInput == "Room" || userInput == "room" || userInput == "4") {
    // Display rooms.
    userInput = "";
    view.printRooms();
    println("Select class to display (dentists, patients, appointments or rooms).");
    printMenu(1); // Print submenu options.
    displayMenu(); // Return to display menu.
  } else if (userInput == "Return" || userInput == "return" || userInput == "5") {
    // Return to main menu.
    userInput = "";
    printMenu(0); // Print main menu options.
    mainMenu();  // Return to main menu.
  } else {
    // Handle invalid input.
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    displayMenu();  // Return to display menu.
  }
   
}

// Implementation of bookMenu method in Interface class.
void Interface::bookMenu() {
  
  std::cin  >> userInput; // Get user input.

    // Handle user input for different booking options.
    if (userInput == "Display" || userInput == "display" || userInput == "1") {
    // Display submenu for viewing data.
    userInput = "";
    println("Select class to display (dentists, patients, appointments or rooms).");
  } else if (userInput == "Book" || userInput == "book" || userInput == "2") {
    // Initiate booking process.
    userInput = "";
    book.startBookingProcess();
  } else if (userInput == "Date" || userInput == "date" || userInput == "3") {
    // Display date.
    userInput = "";
    println("Enter date to display (in days from today).");
  } else if (userInput == "Exit" || userInput == "exit" || userInput == "4") {
    // Exit program.
    userInput = "";
    println("Exiting programme.");
    exit(0); // Terminate program.
  } else {
    // Handle invalid input.
    userInput = "";
    println("Invalid input. Select one of the listed commands.");
    bookMenu(); // Return to booking menu.
  }
   
}
