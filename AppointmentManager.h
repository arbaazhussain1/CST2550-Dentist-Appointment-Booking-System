#include "Appointment.h" // Include the header file for the Appointment class
#include "DentistManager.h" // Include the header file for the DentistManager class
#include "CSVSearcher.h" // Include the header file for the CSVSearcher class
#include <vector> // Include the vector header
#include <string> // Include the string header

class AppointmentManager {
    DentistManager& dentistManager; // Reference to DentistManager object
public:
    // Constructor to initialize DentistManager reference
    AppointmentManager(DentistManager& dm) : dentistManager(dm) {}

    // Function to populate appointments from a CSV file
    // Adjusted to take a reference to an external appointments vector
    void populateAppointmentsFromCSV(const std::string& filename, std::vector<Appointment>& appointments);
};
