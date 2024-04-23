#include "Room.h"

void Room::setID(int ID) {
  roomID = ID;
}

int Room::getID() const {
  return roomID;
}

std::vector<Appointment> Room::getAppointments() const {
  return appointments;
}
