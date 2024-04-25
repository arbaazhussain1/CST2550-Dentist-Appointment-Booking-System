#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h" // Include the header file for the base class Person

class Patient : public Person {
 private:
 int patientID; // Member variable to store the patient ID

 public:
    // Constructor with parameters to initialize the Patient object
    Patient(const std::string& t, const std::string& fn, const std::string& sn, const std::string& a, const std::string& e, int ID) : Person(t, fn, sn, a, e) {
    setPatientID(ID);  // Initialize the patient ID
  }

  // Public setter method to set the patient ID
  void setPatientID(int ID);

  // Public getter method to get the patient ID
  int getPatientID() const;
};

#endif // PATIENT_H
