#include "DentistManager.h"

// Method to find or create a dentist
Dentist* DentistManager::findOrCreateDentist(const std::string& name) {
    // Search for existing dentist
    for (auto* dentist : dentists) {
        if (dentist->getFirstName() + " " + dentist->getSurname() == name) {
            return dentist; // Return existing dentist if found
        }
    }
    // If dentist not found, create a new one
    auto* newDentist = new Dentist("Dr.", name, "", "", "", dentists.size() + 1, 0);
    dentists.push_back(newDentist); // Add new dentist to the list
    return newDentist;
}

// Destructor to deallocate memory
DentistManager::~DentistManager() {
    for (auto* dentist : dentists) {
        delete dentist; // Delete each dentist object
    }
}
