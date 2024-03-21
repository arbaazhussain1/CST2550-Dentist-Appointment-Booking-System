#include "Appointment.h"

//Setter methods.

void Appointment::setRoom(int newRoom) {
  room = newRoom;
}

void Appointment::setDate(std::chrono::system_clock::time_point newDate) {
  date = newDate;
}

void Appointment::setDentist(Dentist* newDentist) {
  dentist = newDentist;
}

void Appointment::setPatient(Patient* newPatient) {
    if (isFree) {
        patient = newPatient;
        isFree = false;
    }
}

//Getter methods.

int Appointment::getRoom() const {
  return room;
}

std::chrono::system_clock::time_point Appointment::getDate() const {
  return date;
}

Dentist* Appointment::getDentist() const {
  return dentist;
}

Patient* Appointment::getPatient() const {
  return patient;
}

bool Appointment::getIsFree() const {
  return isFree;
}
