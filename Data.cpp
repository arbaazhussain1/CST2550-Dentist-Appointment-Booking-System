// Include necessary header files
#include <iostream>
#include "Data.h" // This file defines the implementation of the Data class declared in "Data.h".
#include <fstream>
#include <iomanip>


// Implementation of the setter and getter methods for the Data class

//Setter methods.

// Setter method for setting the dentists data.
void Data::setDentists(std::vector<Dentist> d) {
  dentists = d;
}

// Setter method for setting the patients data.
void Data::setPatients(std::vector<Patient> p) {
  patients = p;
}

// Setter method for setting the appointments data.
void Data::setAppointments(std::vector<Appointment> a) {
  appointments = a;
}

// Setter method for setting the rooms data.
void Data::setRooms(std::vector<Room> r) {
  rooms = r;
}

//Adder methods.

// Method for adding a new dentist.
void Data::addDentist(Dentist d) {
  dentists.push_back(d);
}

// Method for adding a new patient.
void Data::addPatient(Patient p) {
  patients.push_back(p);
}

// Method for adding a new appointment.
void Data::addAppointment(Appointment a) {
  appointments.push_back(a);
}

// Method for adding a new room.
void Data::addRoom(Room r) {
  rooms.push_back(r);
}

//Remover methods.

// Method for removing a dentist.
void Data::removeDentist(Dentist d) {
  for (unsigned short int i; i < dentists.size(); i++) {
     if (dentists[i].getDentistID() == d.getDentistID()) {
       dentists.erase(dentists.begin() + i);
       std::cout << i << " " << dentists[i].getFirstName() << " " << dentists[i].getSurname() << std::endl;
     }
   }
}

// Method for removing a patient.
void Data::removePatient(Patient p) {
  for (unsigned short int i; i < patients.size(); i++) {
     if (patients[i].getPatientID() == p.getPatientID()) {
       patients.erase(patients.begin() + i);
       std::cout << i << " " << patients[i].getFirstName() << " " << patients[i].getSurname() << std::endl;
     }
   }
}

// Method for removing an appointment.
void Data::removeAppointment(Appointment a) {
  for (unsigned short int i; i < appointments.size(); i++) {
     if (appointments[i].getID() == a.getID()) {
       appointments.erase(appointments.begin() + i);
       std::cout << i << " " << appointments[i].getID() << std::endl;
     }
   }
}

// Method for removing a room.
void Data::removeRoom(Room r) {
  for (unsigned short int i; i < rooms.size(); i++) {
     if (rooms[i].getID() == r.getID()) {
       rooms.erase(rooms.begin() + i);
       std::cout << i << " " << rooms[i].getID() << std::endl;
     }
   }
}

//Getter methods.

// Method for getting an appointment by ID.
Appointment* Data::getAppointmentById(int appointmentId) {
    for (auto& appointment : appointments) {
        if (appointment.getID() == appointmentId) {
            return &appointment;
        }
    }
    return nullptr;
}

// Method for getting the dentists data.
std::vector<Dentist> Data::getDentists() const {
  return dentists;
}

// Method for getting the patients data.
std::vector<Patient> Data::getPatients() const {
  return patients;
}

// Method for getting the appointments data.
std::vector<Appointment>& Data::getAppointments() {
    return appointments;
}

// Method for getting the rooms data.
std::vector<Room> Data::getRooms() const {
  return rooms;
}

// Method for getting a dentist by index.
Dentist* Data::getDentist(int index) {
  return &dentists[index];
}

// Method for getting a patient by index.
Patient* Data::getPatient(int index) {
  return &patients[index];
}

// Method for getting an appointment by index.
Appointment Data::getAppointment(int index) const {
  return appointments[index];
}

// Method for getting a room by index.
Room* Data::getRoom(int index) {
  return &rooms[index];
}

// Method for getting the patients data as a reference.
std::vector<Patient>& Data::getPatients() {
    return patients;
}

// Method for getting the maximum patient ID.
int Data::getMaxPatientID() {
    int maxId = 0;
    for (const auto& patient : getPatients()) {
        if (patient.getPatientID() > maxId) {
            maxId = patient.getPatientID();
        }
    }
    return maxId;
}

// Save to csv methods.

// Method for saving appointments data to a CSV file.
void Data::saveAppointmentsToCSV(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    outFile << "Appointment ID,Room ID,Dentist ID,Patient ID,Time,Follow Up,Original Appointment ID\n";

    for (const auto& appointment : appointments) {
        auto timePoint = appointment.getDate();
        auto unixTime = std::chrono::system_clock::to_time_t(timePoint); 

        outFile << appointment.getID() << ","
                << (appointment.getRoom() ? std::to_string(appointment.getRoom()->getID()) : "0") << ","
                << (appointment.getDentist() ? std::to_string(appointment.getDentist()->getDentistID()) : "0") << ","
                << (appointment.getPatient() ? std::to_string(appointment.getPatient()->getPatientID()) : "0") << ","
                << unixTime << ","
                << (appointment.getFollowUp() ? "1" : "0") << ","
                << appointment.getOriginalAppointmentId() << "\n";
    }

    outFile.close();
    std::cout << "Appointments saved to " << filename << std::endl;
}