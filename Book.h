#ifndef BOOK_H
#define BOOK_H

// Include necessary files
#include "Data.h"
#include "View.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Patient.h"
#include <vector>
#include <iostream>

class Book {
private:
    Data* data; // Pointer to Data object for accessing data
    View* view; // Pointer to View object for displaying information
    std::string userInput = ""; // Store user input for processing

public:
    Book(Data* data, View* view); // Constructor taking Data and View objects
    void startBookingProcess(); // Start the booking process
    void selectPatient();  // Select a patient for a new appointment
    void selectDentist(Patient* patient); // Select a dentist for a patient
    void selectAppointmentById(Patient* patient, Dentist* dentist);  // Select an appointment for a patient
    void selectFollowUpAppointmentById(Patient* patient, Dentist* dentist, int originalAppointmentId); // Select a follow-up appointment
    void confirmBooking(Appointment* appointment); // Confirm booking and save to file
    void startFollowUpBookingProcess(); // Start the follow-up booking process
    void selectBookingOption();  // Select new or follow-up appointment
};

#endif
