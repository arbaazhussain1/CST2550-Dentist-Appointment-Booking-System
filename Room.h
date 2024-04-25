#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "Appointment.h" // Include the header file for Appointment class

//Prototype class for 'Appointment', to prevent recursive inclusion.
class Appointment;

class Room {
 private:
  int roomID; // Member variable to store the room ID
  std::vector<Appointment> appointments;  // Vector to store appointments scheduled in the room
public:
  Room() { // Default constructor
    setID(0); // Initialize room ID to 0
  }
  Room(int ID) { // Parameterized constructor
    setID(ID); // Initialize room ID to the specified value
  }

  // Public setter method to set the room ID
  void setID(int ID);

  // Public getter methods to retrieve room ID and appointments
  int getID() const;
  std::vector<Appointment> getAppointments() const;
};

#endif // ROOM_H
