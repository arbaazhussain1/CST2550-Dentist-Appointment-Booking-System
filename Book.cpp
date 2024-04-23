#include "Book.h"
#include "Print_Functions.h"
#include "Input_Validation.h"
#include <iostream>
#include <limits>
#include <string>
#include <regex>
#include <chrono>
#include <iomanip>
#include <sstream>

Book::Book(Data* data, View* view) : data(data), view(view) {}

void Book::startBookingProcess() {
    selectBookingOption();
}

void Book::selectBookingOption() {
  println("Book new or follow-up appointment? (1 for new, 2 for follow-up)");
  std::cin  >> userInput;
  if (userInput == "New" || userInput == "new" || userInput == "1") {
    userInput = "";
    view->printPatients();
    selectPatient();
  } else if (userInput == "Follow up" || userInput == "follow up" || userInput == "follow-up" || userInput == "Follow-up" || userInput == "2") {
    userInput = "";
    startFollowUpBookingProcess();
  }
}

void Book::selectPatient() {
  std::string patientInput;
  int patientID;
  bool valid = false;
  std::cout << "Enter patient ID (press 0 to cancel): ";
  std::cin >> patientInput;
  
  if (isIntegerString(patientInput)) {
    patientID = stoi(patientInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectPatient();
  }

  if (valid) {
    Patient* patient = data->getPatient(patientID - 1); 
    if (patientID != 0) {
      if (patient != nullptr) {
        view->printDentists();
        selectDentist(patient);
      } else {
        println("Invalid patient ID, try again.");
        startBookingProcess();
      }
    } else {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::selectDentist(Patient* patient) {
  std::string dentistInput;
  int dentistID;
  bool valid = false;
  std::cout << "Enter dentist ID (press 0 to cancel): ";
  std::cin >> dentistInput;
  
  if (isIntegerString(dentistInput)) {
    dentistID = stoi(dentistInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectDentist(patient);
  }

  if (valid) {
    Dentist* dentist = data->getDentist(dentistID - 1);  
    if (dentistID != 0) {
      if (dentist != nullptr) {
        view->printDoctorsAvailableAppointments(dentistID);
        selectAppointmentById(patient, dentist);
      } else {
	println("Invalid patient ID, try again.");
        selectDentist(patient);
      }
    } else {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::selectFollowUpAppointmentById(Patient* patient, Dentist* dentist, int originalAppointmentId) {
    std::cout << "Enter new appointment ID for follow-up (press 0 to cancel): ";
    std::string appointmentInput;
    std::cin >> appointmentInput;

    if (appointmentInput == "0") {
        std::cout << "Follow-up booking process cancelled.\n";
        return;
    }

    int appointmentId = stoi(appointmentInput);
    auto& appointments = data->getAppointments();
    bool found = false;

    for (auto& appointment : appointments) {
        if (appointment.getDentist() == dentist &&
            appointment.getID() == appointmentId &&
            !appointment.getPatient()) { 
            appointment.setPatient(patient);
            appointment.setFollowUp(true); 
            appointment.setOriginalAppointmentId(originalAppointmentId);
            std::cout << "Follow-up appointment booked successfully.\n";
            confirmBooking(&appointment);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid appointment ID or appointment is not available, try again.\n";
        selectFollowUpAppointmentById(patient, dentist, originalAppointmentId); 
    }
}

void Book::selectAppointmentById(Patient* patient, Dentist* dentist) {
  std::cout << "Enter appointment ID (press 0 to cancel): ";
  std::string appointmentInput;
  int appointmentId;
  bool valid = false;
  std::cin >> appointmentInput;

  if (isIntegerString(appointmentInput)) {
    appointmentId = stoi(appointmentInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectAppointmentById(patient, dentist);
  }

  if (valid) {
    auto& appointments = data->getAppointments();
    bool found = false;
  
    for (auto& appointment : appointments) {
      if (appointment.getDentist() == dentist &&
        appointment.getID() == appointmentId &&
        !appointment.getPatient()) {
              appointment.setPatient(patient);
        std::cout << "Appointment booked successfully.\n";
        confirmBooking(&appointment);
        found = true;
        break;
      }
    }

    if (!found && appointmentId != 0) {
      println("Invalid appointment ID or appointment is not available, try again.");
      selectAppointmentById(patient, dentist);
    } else if (!found) {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::startFollowUpBookingProcess() {
    std::cout << "Follow-Up Booking Process\n";

    std::cout << "Select a patient for follow-up:\n";
    view->printPatients();
    std::string patientInput;
    std::cout << "Enter Patient ID (press 0 to cancel): ";
    std::cin >> patientInput;

    if (patientInput == "0") {
        std::cout << "Follow-up booking process cancelled.\n";
        return;
    }

    int patientId = stoi(patientInput);
    Patient* patient = data->getPatient(patientId - 1);
    if (!patient) {
        std::cout << "Invalid patient ID.\n";
        return;
    }

    std::cout << "Select a dentist for follow-up:\n";
    view->printDentists();
    std::string dentistInput;
    std::cout << "Enter Dentist ID (press 0 to cancel): ";
    std::cin >> dentistInput;

    if (dentistInput == "0") {
        std::cout << "Follow-up booking process cancelled.\n";
        return;
    }

    int dentistId = stoi(dentistInput);
    Dentist* dentist = data->getDentist(dentistId - 1);
    if (!dentist) {
        std::cout << "Invalid dentist ID.\n";
        return;
    }

    view->printAllAppointmentsForDentistAndPatient(dentistId, patientId);

    std::cout << "Enter the ID of the appointment you want to follow up on (press 0 to cancel): ";
    std::string appointmentInput;
    std::cin >> appointmentInput;

    if (appointmentInput == "0") {
        std::cout << "Follow-up booking process cancelled.\n";
        return;
    }

    int appointmentId = stoi(appointmentInput);
    Appointment* originalAppointment = data->getAppointmentById(appointmentId);
    if (!originalAppointment || !originalAppointment->getPatient()) {
        std::cout << "Invalid appointment ID or no original appointment found.\n";
        return;
    }

    std::cout << "Booking follow-up appointment...\n";
    view->printDoctorsAvailableAppointments(dentist->getDentistID());
    selectFollowUpAppointmentById(patient, dentist, appointmentId);
}


void Book::confirmBooking(Appointment* appointment) {
    
  data->saveAppointmentsToCSV("appointments.csv");
  std::time_t appointmentTime = std::chrono::system_clock::to_time_t(appointment->getDate());
  std::cout << "Booking confirmed for " << appointment->getPatient()->getFirstName()
            << " with Dr. " << appointment->getDentist()->getFirstName()
            << " on " <<  std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d at %H:%M") << "\n";
}
