#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <chrono>
#include "Dentist.h"
#include "Patient.h"

class Appointment {
 private:
  int room;
  std::chrono::system_clock::time_point date;
  Dentist* dentist;
  Patient* patient;
  bool isFree;
  
 public:
  Appointment(int r, std::chrono::system_clock::time_point dt, Dentist* d) {
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(nullptr);
    isFree = true;
  }

  //Public setter methods.
  void setRoom(int newRoom);
  void setDate(std::chrono::system_clock::time_point newDate);
  void setDentist(Dentist* newDentist);
  void setPatient(Patient* newPatient);

  //Public getter methods.
  int getRoom() const;
  std::chrono::system_clock::time_point getDate() const;
  Dentist* getDentist() const;
  Patient* getPatient() const;
  bool getIsFree() const;
};

#endif // APPOINTMENT_H
