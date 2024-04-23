#include <iostream>
#include "Data.h"
#include <fstream>
#include <iomanip>

//Setter methods.

void Data::setDentists(std::vector<Dentist> d) {
  dentists = d;
}
  
void Data::setPatients(std::vector<Patient> p) {
  patients = p;
}
  
void Data::setAppointments(std::vector<Appointment> a) {
  appointments = a;
}
  
void Data::setRooms(std::vector<Room> r) {
  rooms = r;
}

//Adder methods.

void Data::addDentist(Dentist d) {
  dentists.push_back(d);
}

void Data::addPatient(Patient p) {
  patients.push_back(p);
}

void Data::addAppointment(Appointment a) {
  appointments.push_back(a);
}
 
void Data::addRoom(Room r) {
  rooms.push_back(r);
}

//Remover methods.

void Data::removeDentist(Dentist d) {
  for (unsigned short int i; i < dentists.size(); i++) {
     if (dentists[i].getDentistID() == d.getDentistID()) {
       dentists.erase(dentists.begin() + i);
       std::cout << i << " " << dentists[i].getFirstName() << " " << dentists[i].getSurname() << std::endl;
     }
   }
}

void Data::removePatient(Patient p) {
  for (unsigned short int i; i < patients.size(); i++) {
     if (patients[i].getPatientID() == p.getPatientID()) {
       patients.erase(patients.begin() + i);
       std::cout << i << " " << patients[i].getFirstName() << " " << patients[i].getSurname() << std::endl;
     }
   }
}

void Data::removeAppointment(Appointment a) {
  for (unsigned short int i; i < appointments.size(); i++) {
     if (appointments[i].getID() == a.getID()) {
       appointments.erase(appointments.begin() + i);
       std::cout << i << " " << appointments[i].getID() << std::endl;
     }
   }
}

void Data::removeRoom(Room r) {
  for (unsigned short int i; i < rooms.size(); i++) {
     if (rooms[i].getID() == r.getID()) {
       rooms.erase(rooms.begin() + i);
       std::cout << i << " " << rooms[i].getID() << std::endl;
     }
   }
}

//Getter methods.

Appointment* Data::getAppointmentById(int appointmentId) {
    for (auto& appointment : appointments) {
        if (appointment.getID() == appointmentId) {
            return &appointment;
        }
    }
    return nullptr;
}

// Getter methods.

std::vector<Dentist> Data::getDentists() const {
  return dentists;
}

std::vector<Patient> Data::getPatients() const {
  return patients;
}

std::vector<Appointment>& Data::getAppointments() {
    return appointments;
}

std::vector<Room> Data::getRooms() const {
  return rooms;
}

Dentist* Data::getDentist(int index) {
  return &dentists[index];
}

Patient* Data::getPatient(int index) {
  return &patients[index];
}

Appointment Data::getAppointment(int index) const {
  return appointments[index];
}

Room* Data::getRoom(int index) {
  return &rooms[index];
}

std::vector<Patient>& Data::getPatients() {
    return patients;
}

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