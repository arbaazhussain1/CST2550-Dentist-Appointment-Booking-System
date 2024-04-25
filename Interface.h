#ifndef INTERFACE_H
#define INTERFACE_H

#include "Data.h" // Include header file for Data class
#include "Calendar.h" // Include header file for Calendar class
#include "View.h" // Include header file for View class
#include "Book.h" // Include header file for Book class
#include "PatientManager.h" // Include header file for PatientManager class

// Interface class declaration
class Interface {
 private:
  Data* data; // Pointer to Data object
  PatientManager* patientManager; // Pointer to PatientManager object
  Calendar calendar; // Calendar object
  View view; // View object
  Book book; // Book object
  std::string userInput = ""; // String to store user input
  std::string menuOptions[2][6] = { // Array to store menu options
    {"1) Display", "2) Book", "3) Date", "4) Add Patient", "5) Exit"}, // Main menu options
    {"1) Dentist", "2) Patient", "3) Appointment", "4) Room", "5) Return"} // Display menu options
  };
 public:
    // Constructor
    Interface(Data* d, View& v, Book& b) : data(d), view(v), book(b) {
    patientManager = new PatientManager(d); // Initialize PatientManager object
  }
   ~Interface() {
      delete patientManager; // Delete PatientManager object to release memory
  }
    // Method to print menu options
    void printMenu(short int menu);
    // Method for main menu
    void mainMenu();
    // Method for display menu
    void displayMenu();
    // Method for book menu
    void bookMenu();
};

#endif // INTERFACE_H
