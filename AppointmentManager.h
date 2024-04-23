#include "Appointment.h"
#include "DentistManager.h"
#include "CSVSearcher.h"
#include <vector>
#include <string>

class AppointmentManager {
    DentistManager& dentistManager;
public:
    AppointmentManager(DentistManager& dm) : dentistManager(dm) {}

    // Adjusted to take a reference to an external appointments vector
    void populateAppointmentsFromCSV(const std::string& filename, std::vector<Appointment>& appointments);
};
