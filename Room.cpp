#include "Room.h" // Include the header file for the Room class

// Implementation of the setter and getter methods for the Room class

// Setter method to set the room ID
void Room::setID(int ID) {
  roomID = ID;
}

// Getter method to retrieve the room ID
int Room::getID() const {
  return roomID;
}

// Getter method to retrieve the vector of appointments scheduled in the room
std::vector<Appointment> Room::getAppointments() const {
  return appointments;
}
