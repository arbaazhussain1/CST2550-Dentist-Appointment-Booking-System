#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Data.h"

class PatientManager {
private:
    Data* data;

public:
    PatientManager(Data* d) : data(d) {}
    void addNewPatient();
    void savePatientsToCSV();
};

#endif
