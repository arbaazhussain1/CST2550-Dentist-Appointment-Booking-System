#include "DentistManager.h"

Dentist* DentistManager::findOrCreateDentist(const std::string& name) {
    for (auto* dentist : dentists) {
        if (dentist->getFirstName() + " " + dentist->getSurname() == name) {
            return dentist;
        }
    }
    auto* newDentist = new Dentist("Dr.", name, "", "", "", dentists.size() + 1, 0);
    dentists.push_back(newDentist);
    return newDentist;
}

DentistManager::~DentistManager() {
    for (auto* dentist : dentists) {
        delete dentist;
    }
}
