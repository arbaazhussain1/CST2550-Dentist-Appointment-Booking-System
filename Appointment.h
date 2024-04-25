#ifndef APPOINTMENT_H
#define APPOINTMENT_H

// Include necessary header files
#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include <chrono>

// Forward declaration of the Room class to avoid recursive inclusion.
class Room;

// Class declaration for the Appointment class.
class Appointment {
 private:
  int appointmentID; // Unique identifier for the appointment.
  Room* room; // Pointer to the room where the appointment takes place.
  std::chrono::system_clock::time_point date; // Date and time of the appointment.
  Dentist* dentist; // Pointer to the dentist assigned to the appointment.
  Patient* patient;  // Pointer to the patient assigned to the appointment.
  bool isFree;   // Flag indicating whether the appointment is available.
  bool followUp;  // Flag indicating whether the appointment is a follow-up.
  int originalAppointmentId;  // ID of the original appointment for follow-ups.
  
 public:
    // Constructors for the Appointment class.
    Appointment(int ID, Room* r, std::chrono::system_clock::time_point dt, Dentist* d) {
    setID(ID);
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(nullptr);
    isFree = false;
  }
  
  Appointment(int ID, Room* r, std::chrono::system_clock::time_point dt, Dentist* d, Patient* p) {
    setID(ID);
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(p);
    isFree = false;
  }

  // Public setter methods to assign values to private member variables.
  void setID(int ID);
  void setRoom(Room* newRoom);
  void setDate(std::chrono::system_clock::time_point newDate);
  void setDentist(Dentist* newDentist);
  void setPatient(Patient* newPatient);
  void setFollowUp(bool value) { followUp = value; }
  void setOriginalAppointmentId(int value) { originalAppointmentId = value; }

  // Public getter methods to retrieve values of private member variables.
  int getID() const;
  Room* getRoom() const;
  std::chrono::system_clock::time_point getDate() const;
  Dentist* getDentist() const;
  Patient* getPatient() const;
  bool getIsFree() const;
  bool getFollowUp() const { return followUp; }
  int getOriginalAppointmentId() const { return originalAppointmentId; }
};

#endif // APPOINTMENT_H
