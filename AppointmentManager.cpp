#include "AppointmentManager.h" // Include the header file for the AppointmentManager class
#include "DateTimeUtils.h" // Include the header file for DateTimeUtils

// Function to populate appointments from a CSV file
void AppointmentManager::populateAppointmentsFromCSV(const std::string& filename, std::vector<Appointment>& appointments) {
    CSVSearcher searcher; // Create an instance of CSVSearcher
    auto csvData = searcher.readCSV(filename);  // Read CSV data from the file

    // Iterate over each line of CSV data
    for (const auto& lineData : csvData) {
        if (lineData.size() < 5) continue;  // Skip if the line doesn't contain enough data

        int room = std::stoi(lineData[0]);  // Extract room number from CSV data
        std::string dentistName = lineData[1]; // Extract dentist's name from CSV data
        std::string timeStr = lineData[3]; // Extract time string from CSV data
        std::string dateStr = lineData[4]; // Extract date string from CSV data
        
        auto appointmentTime = parseDateTime(timeStr, dateStr); // Parse date and time string into a time_point object
        Dentist* dentist = dentistManager.findOrCreateDentist(dentistName); // Find or create a Dentist object based on the name

        // Create a new Appointment object and add it to the appointments vector
        appointments.emplace_back(room, appointmentTime, dentist);
    }
}
