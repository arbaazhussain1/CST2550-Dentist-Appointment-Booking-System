#ifndef DENTIST_MANAGER_H
#define DENTIST_MANAGER_H

#include "Dentist.h" // Include the Dentist class header file
#include <vector> // Include the vector library
#include <string> // Include the string library

class DentistManager {
    std::vector<Dentist*> dentists; // Vector to store pointers to Dentist objects
public:
    // Method to find or create a Dentist object by name
    Dentist* findOrCreateDentist(const std::string& name);
    // Destructor to deallocate memory for Dentist objects
    ~DentistManager();
};

#endif // DENTIST_MANAGER_H // Include guard end
