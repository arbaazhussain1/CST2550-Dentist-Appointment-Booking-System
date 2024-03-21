#include "QuickSort.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

void QuickSort::sortAppointments(std::vector<Appointment>& appointments) {
    quicksort(appointments, 0, appointments.size() - 1);
}

int QuickSort::partition(std::vector<Appointment>& appointments, int low, int high) {
    auto pivot = appointments[high].getDate();
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (appointments[j].getDate() < pivot) {
            i++;
            std::swap(appointments[i], appointments[j]);
        }
    }
    std::swap(appointments[i + 1], appointments[high]);
    return (i + 1);
}

void QuickSort::quicksort(std::vector<Appointment>& appointments, int low, int high) {
    if (low < high) {
        int pi = partition(appointments, low, high);
        quicksort(appointments, low, pi - 1);
        quicksort(appointments, pi + 1, high);
    }
}

void QuickSort::printFreeAppointments(const std::vector<Appointment>& appointments) {
    for (const auto& appointment : appointments) {
        if (appointment.getIsFree()) {
            auto time = std::chrono::system_clock::to_time_t(appointment.getDate());
            std::cout << "Room: " << appointment.getRoom()
                      << ", Date: " << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M")
                      << ", Dentist: " << appointment.getDentist()->getFirstName()
                      << ", Status: Free\n";
        }
    }
}

void QuickSort::printAppointments(const std::vector<Appointment>& appointments) {
    for (const auto& appointment : appointments) {
        auto time = std::chrono::system_clock::to_time_t(appointment.getDate());
        std::cout << "Room: " << appointment.getRoom()
                  << ", Date: " << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M")
                  << ", Dentist: " << appointment.getDentist()->getFirstName()
                  << ", Status: " << (appointment.getIsFree() ? "Free" : "Booked") << "\n"; // Updated to reflect booked status
    }
}
