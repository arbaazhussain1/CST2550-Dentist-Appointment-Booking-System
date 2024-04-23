#ifndef DATA_H
#define DATA_H

#include <vector>
#include "Dentist.h"
#include "Patient.h"
#include "Appointment.h"
#include "Room.h"

//Prototype classes, to prevent recursive inclusion.

class Dentist;
class Patient;
class Appointment;
class Room;

class Data {
 private:
  std::vector<Dentist> dentists;
  std::vector<Patient> patients;
  std::vector<Appointment> appointments;
  std::vector<Room> rooms;
 public:
  //Public setter methods.
  void setDentists(std::vector<Dentist> d);
  void setPatients(std::vector<Patient> p);
  void setAppointments(std::vector<Appointment> a);
  void setRooms(std::vector<Room> r);
  Appointment* getAppointmentById(int appointmentId);

  //Public adder methods.
  void addDentist(Dentist d);
  void addPatient(Patient p);
  void addAppointment(Appointment a);
  void addRoom(Room r);

  //Public remover methods.
  void removeDentist(Dentist d);
  void removePatient(Patient p);
  void removeAppointment(Appointment a);
  void removeRoom(Room r);

  //Public getter methods.
  std::vector<Dentist> getDentists() const;
  std::vector<Patient> getPatients() const;
  std::vector<Appointment>& getAppointments();
  std::vector<Room> getRooms() const;
  std::vector<Patient>& getPatients();
  
  int getMaxPatientID();
  Dentist* getDentist(int index) ;
  Patient* getPatient(int index) ;
  Appointment getAppointment(int index) const;
  Room* getRoom(int index) ;

  //Public save to csv methods.
  void saveAppointmentsToCSV(const std::string& filename);
};

#endif // DATA_H
