#ifndef INTERFACE_H
#define INTERFACE_H

#include "Data.h"
#include "Calendar.h"
#include "View.h"
#include "Book.h"
#include "PatientManager.h"

class Interface {
 private:
  Data* data;
  PatientManager* patientManager;
  Calendar calendar;
  View view;
  Book book;
  std::string userInput = "";
  std::string menuOptions[2][6] = {
    {"1) Display", "2) Book", "3) Date", "4) Add Patient", "5) Exit"},
    {"1) Dentist", "2) Patient", "3) Appointment", "4) Room", "5) Return"}
  };
 public:
  Interface(Data* d, View& v, Book& b) : data(d), view(v), book(b) {
    patientManager = new PatientManager(d);
  }
  ~Interface() {
      delete patientManager;
  }
  void printMenu(short int menu);
  void mainMenu();
  void displayMenu();
  void bookMenu();
};

#endif
