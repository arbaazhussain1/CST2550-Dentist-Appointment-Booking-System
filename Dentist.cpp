#include "Dentist.h"

// Implementation of the setter and getter methods for the Dentist class

//Setter methods.

// Setter method for setting the dentist ID.
void Dentist::setDentistID(int ID) {
  dentistID = ID;
}

// Setter method for setting the salary of the dentist.
void Dentist::setSalary(int s) {
  salary = s;
}

//Getter methods.

// Getter method for retrieving the dentist ID.
int Dentist::getDentistID() const {
  return dentistID;
}

// Getter method for retrieving the salary of the dentist.s
int Dentist::getSalary() const {
  return salary;
}
