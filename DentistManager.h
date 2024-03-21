#ifndef DENTIST_MANAGER_H
#define DENTIST_MANAGER_H

#include "Dentist.h"
#include <vector>
#include <string>

class DentistManager {
    std::vector<Dentist*> dentists;
public:
    Dentist* findOrCreateDentist(const std::string& name);
    ~DentistManager();
};

#endif // DENTIST_MANAGER_H // Include guard end
