#include "AppointmentManager.h"
#include "DateTimeUtils.h"

void AppointmentManager::populateAppointmentsFromCSV(const std::string& filename, std::vector<Appointment>& appointments) {
    CSVSearcher searcher;
    auto csvData = searcher.readCSV(filename);

    for (const auto& lineData : csvData) {
        if (lineData.size() < 5) continue;

        int room = std::stoi(lineData[0]);
        std::string dentistName = lineData[1];
        std::string timeStr = lineData[3];
        std::string dateStr = lineData[4];
        
        auto appointmentTime = parseDateTime(timeStr, dateStr);
        Dentist* dentist = dentistManager.findOrCreateDentist(dentistName);

        appointments.emplace_back(room, appointmentTime, dentist);
    }
}
