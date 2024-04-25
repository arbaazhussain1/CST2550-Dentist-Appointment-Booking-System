#include "Patient.h" // Include the header file for the Patient class

// Implementation of the setter and getter methods for the Patient class

// Setter method to set the patient ID
void Patient::setPatientID(int ID) {
    patientID = ID; // Set the patient ID
}

// Getter method to get the patient ID
int Patient::getPatientID() const {
    return patientID; // Return the patient ID
}
