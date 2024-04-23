#include <iostream>
#include "View.h"
#include "Print_Functions.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include "QuickSort.h" 

void View::printDentists() {
  for (unsigned short int i = 0; i < data->getDentists().size(); i++) {
    Dentist* dentist = data->getDentist(i); 
    if (dentist != nullptr) {  
      std::cout << dentist->getDentistID() << ") " << dentist->getTitle() << " "
                << dentist->getFirstName() << " " << dentist->getSurname() << std::endl;
    }
  }
}


void View::printPatients() {
  for (unsigned short int i = 0; i < data->getPatients().size(); i++) {
    Patient* patient = data->getPatient(i);
    if (patient != nullptr) {
      std::cout << patient->getPatientID() << ") " << patient->getTitle() << " "
                << patient->getFirstName() << " " << patient->getSurname() << std::endl;
    }
  }
}


void View::printRooms() {
  for (unsigned short int i = 0; i < data->getRooms().size(); i++) {
    Room* room = data->getRoom(i);  
    if (room != nullptr) {  
      std::cout << "Room No." << room->getID() << std::endl;
    }
  }
}

void View::printAppointments() {
    const std::vector<Appointment>& appointments = data->getAppointments();
    for (unsigned short int i = 0; i < appointments.size(); i++) {
        const Appointment& app = appointments[i];

        std::cout << "APPOINTMENT  " << i + 1 << std::endl;
        std::cout << "ID: " << app.getID() << std::endl;

        if (app.getRoom()) {
            std::cout << "Room: " << app.getRoom()->getID() << std::endl;
        } else {
            std::cout << "Room: None" << std::endl;
        }

        if (app.getDentist()) {
            std::cout << "Dentist: " << app.getDentist()->getTitle() << " " 
                      << app.getDentist()->getFirstName() << " " 
                      << app.getDentist()->getSurname() << std::endl;
        } else {
            std::cout << "Dentist: None" << std::endl;
        }

        if (app.getPatient()) {
            std::cout << "Patient ID: " << app.getPatient()->getPatientID() << std::endl;  // Ensure this line is correctly labeled
            std::cout << "Patient: " << app.getPatient()->getTitle() << " " 
                      << app.getPatient()->getFirstName() << " " 
                      << app.getPatient()->getSurname() << std::endl;
        } else {
            std::cout << "Patient: None" << std::endl;
        }

        std::time_t appointmentTime = std::chrono::system_clock::to_time_t(app.getDate());
        std::cout << "Date and Time: " << std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d %H:%M") << std::endl;

        if (app.getFollowUp()) {
            std::cout << "Follow-up Appointment: True" << std::endl;
            std::cout << "Original Appointment ID: " << app.getOriginalAppointmentId() << std::endl;
        }

        std::cout << std::endl;
    }
}

void View::printDoctorsAvailableAppointments(int dentistId) {
      const std::vector<Appointment>& appointments = data->getAppointments();

        std::vector<Appointment> filteredAppointments;
        for (const auto& app : appointments) {
            if (app.getDentist() && app.getDentist()->getDentistID() == dentistId && !app.getPatient()) {
                filteredAppointments.push_back(app);
            }
        }

        QuickSort sorter;
        sorter.sortAppointments(filteredAppointments);  

        std::cout << std::endl;
        std::cout << "Showing available appointments for your chosen Dentist:" << std::endl;
        std::cout << std::endl;

        for (unsigned short int i = 0; i < filteredAppointments.size(); i++) {
            const Appointment& app = filteredAppointments[i];

            std::cout << "APPOINTMENT " << i + 1 << std::endl;
            std::cout << "ID: " << app.getID() << std::endl;

            if (app.getRoom()) {
                std::cout << "Room: " << app.getRoom()->getID() << std::endl;
            } else {
                std::cout << "Room: None" << std::endl;
            }

            if (app.getDentist()) {
                std::cout << "Dentist: " << app.getDentist()->getTitle() << " " 
                          << app.getDentist()->getFirstName() << " " 
                          << app.getDentist()->getSurname() << std::endl;
            } else {
                std::cout << "Dentist: None" << std::endl;
            }
            
            std::cout << "Patient: None" << std::endl;

            std::time_t appointmentTime = std::chrono::system_clock::to_time_t(app.getDate());
            std::cout << "Date and Time: " << std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d %H:%M") << std::endl;

            std::cout << std::endl;
        }
    }

void View::printAllAppointmentsForDentistAndPatient(int dentistId, int patientId) {
    const std::vector<Appointment>& appointments = data->getAppointments();
    std::cout << "Listing all appointments for Dentist ID " << dentistId << " and Patient ID " << patientId << ":\n";
    bool found = false;

    for (unsigned short int i = 0; i < appointments.size(); i++) {
        const Appointment& app = appointments[i];

        if (app.getDentist() && app.getDentist()->getDentistID() == dentistId && 
            app.getPatient() && app.getPatient()->getPatientID() == patientId) {
            found = true;
            std::cout << "APPOINTMENT " << i + 1 << std::endl;
            std::cout << "ID: " << app.getID() << std::endl;
            std::cout << "Room: " << (app.getRoom() ? std::to_string(app.getRoom()->getID()) : "None") << std::endl;
            std::cout << "Dentist: " << app.getDentist()->getTitle() << " " << app.getDentist()->getFirstName() << " " << app.getDentist()->getSurname() << std::endl;
            std::cout << "Patient: " << app.getPatient()->getTitle() << " " << app.getPatient()->getFirstName() << " " << app.getPatient()->getSurname() << std::endl;
            std::time_t appointmentTime = std::chrono::system_clock::to_time_t(app.getDate());
            std::cout << "Date and Time: " << std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d %H:%M") << std::endl;
            
            if (app.getFollowUp()) {
                std::cout << "Follow-up Appointment: True" << std::endl;
                std::cout << "Original Appointment ID: " << app.getOriginalAppointmentId() << std::endl;
            }
            std::cout << std::endl;
        }
    }

    if (!found) {
        std::cout << "No appointments found for the specified dentist and patient.\n";
    }
}
