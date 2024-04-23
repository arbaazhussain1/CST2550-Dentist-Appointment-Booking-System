#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "Appointment.h"

//Prototype class for 'Appointment', to prevent recursive inclusion.

class Appointment;

class Room {
 private:
  int roomID;
  std::vector<Appointment> appointments;
 public:
  Room() {
    setID(0);
  }
  Room(int ID) {
    setID(ID);
  }

  //Public setter methods.
  void setID(int ID);

  //Public getter methods.
  int getID() const;
  std::vector<Appointment> getAppointments() const;
};

#endif
