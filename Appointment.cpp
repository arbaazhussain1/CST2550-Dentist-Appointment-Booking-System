// Include necessary header files
#include "Appointment.h" // This file defines the implementation of the Appointment class declared in "Appointment.h".

// Implementation of the setter and getter methods for the Appointment class

//Setter methods.

// Setter method for setting the appointment ID.
void Appointment::setID(int ID) {
  appointmentID = ID;
}
// Setter method for setting the room for the appointment.
void Appointment::setRoom(Room* newRoom) {
  room = newRoom;
}
// Setter method for setting the date and time for the appointment.
void Appointment::setDate(std::chrono::system_clock::time_point newDate) {
  date = newDate;
}
// Setter method for setting the dentist for the appointment.
void Appointment::setDentist(Dentist* newDentist) {
  dentist = newDentist;
}
// Setter method for setting the patient for the appointment.
void Appointment::setPatient(Patient* newPatient) {
  patient = newPatient;
}

//Getter methods.

// Getter method for retrieving the appointment ID.
int Appointment::getID() const {
  return appointmentID;
}
// Getter method for retrieving the room for the appointment.
Room* Appointment::getRoom() const {
  return room;
}
// Getter method for retrieving the date and time for the appointment.
std::chrono::system_clock::time_point Appointment::getDate() const {
  return date;
}
// Getter method for retrieving the dentist for the appointment.
Dentist* Appointment::getDentist() const {
  return dentist;
}
// Getter method for retrieving the patient for the appointment.
Patient* Appointment::getPatient() const {
  return patient;
}
// Getter method for retrieving the availability status of the appointment.
bool Appointment::getIsFree() const {
  return isFree;
}
