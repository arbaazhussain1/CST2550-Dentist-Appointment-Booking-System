#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Appointment.h"
#include <vector>

class QuickSort {
public:
    // Sorts the vector of Appointment objects
    void sortAppointments(std::vector<Appointment>& appointments);

private:
    // Utility method to partition the vector for quicksort
    int partition(std::vector<Appointment>& appointments, int low, int high);

    // The main quicksort algorithm
    void quicksort(std::vector<Appointment>& appointments, int low, int high);

    // Method to print the sorted appointments
    void printFreeAppointments(const std::vector<Appointment>& appointments);
    void printAppointments(const std::vector<Appointment>& appointments);
};

#endif // QUICKSORT_H
