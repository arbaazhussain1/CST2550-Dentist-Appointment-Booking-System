#ifndef APPOINTMENTDISPLAY_H
#define APPOINTMENTDISPLAY_H

#include "Appointment.h"
#include <vector>

class AppointmentDisplay {
public:
    // Displays available appointments for a given list
    static void displayAppointments(const std::vector<Appointment>& appointments);
};

#endif // APPOINTMENTDISPLAY_H
