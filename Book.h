#ifndef BOOK_H
#define BOOK_H

#include "Data.h"
#include "View.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Patient.h"
#include <vector>
#include <iostream>

class Book {
private:
    Data* data;
    View* view;
    std::string userInput = "";

public:
    Book(Data* data, View* view);
    void startBookingProcess();
    void selectPatient();
    void selectDentist(Patient* patient);
    void selectAppointmentById(Patient* patient, Dentist* dentist);
    void selectFollowUpAppointmentById(Patient* patient, Dentist* dentist, int originalAppointmentId);
    void confirmBooking(Appointment* appointment);
    void startFollowUpBookingProcess();
    void selectBookingOption();
};

#endif
