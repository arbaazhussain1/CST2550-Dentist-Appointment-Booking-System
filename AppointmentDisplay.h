#ifndef APPOINTMENTDISPLAY_H
#define APPOINTMENTDISPLAY_H

#include "Appointment.h" // Include the Appointment header file to access the Appointment class
#include <vector> // Include the vector header file for using std::vector

class AppointmentDisplay {
public:
    // Displays available appointments for a given list
    static void displayAppointments(const std::vector<Appointment>& appointments);
};

#endif // APPOINTMENTDISPLAY_H
