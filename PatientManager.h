#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Data.h" // Include the header file for Data class

class PatientManager {
private:
    Data* data; // Pointer to Data object for managing patient data

public:
    // Constructor to initialize PatientManager with Data object
    PatientManager(Data* d) : data(d) {}

    // Method to add a new patient
    void addNewPatient();
    // Method to save the list of patients to a CSV file
    void savePatientsToCSV();
};

#endif  // PATIENT_MANAGER_H
