#include "Dentist.h"

//Setter methods.

void Dentist::setDentistID(int ID) {
  dentistID = ID;
}

void Dentist::setSalary(int s) {
  salary = s;
}

//Getter methods.

int Dentist::getDentistID() const {
  return dentistID;
}

int Dentist::getSalary() const {
  return salary;
}
