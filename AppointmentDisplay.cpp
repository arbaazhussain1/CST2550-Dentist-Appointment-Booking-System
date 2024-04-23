#include "AppointmentDisplay.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

/*
 * Author: SS4540
 *
 * This function displays available appointments in a neatly formatted table.
 * Each row shows the date and time of the appointment, the name of the dentist, and the room number.
 * Gaps between columns are increased for clarity. This makes it easy to read and understand the schedule at a glance.
 */
void AppointmentDisplay::displayAppointments(const std::vector<Appointment> &appointments)
{
    std::cout << "Appointments:\n";
    std::cout << std::left << std::setw(15) << "Date"
              << std::setw(10) << "Time"
              << std::setw(15) << "Dentist"
              << std::setw(6) << "Room"
              << std::setw(15) << "Availability"
              << "\n";
    std::cout << std::string(58, '-') << "\n";

    for (const auto &appointment : appointments)
    {
        auto dateTime = appointment.getDate();
        auto timeT = std::chrono::system_clock::to_time_t(dateTime);
        std::string dentistName = appointment.getDentist()->getFirstName() + " " + appointment.getDentist()->getSurname();
        std::string status = appointment.getIsFree() ? "Free" : "Booked";

        std::cout << std::left << std::setw(20) << std::put_time(std::localtime(&timeT), "%Y-%m-%d")
                  << std::setw(5) << " " << std::put_time(std::localtime(&timeT), "%H:%M")
                  << std::setw(20) << "     " + dentistName
                  << appointment.getRoom()
                  << std::setw(5) << " " << status << "\n";
    }
}
