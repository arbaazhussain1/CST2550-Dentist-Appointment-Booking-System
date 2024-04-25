#include "DateTimeUtils.h"
#include <sstream>
#include <ctime>

// Function to parse a date and time string into a std::chrono::system_clock::time_point
std::chrono::system_clock::time_point parseDateTime(const std::string& timeStr, const std::string& dateStr) {
    // Initialize a std::tm structure to store the parsed date and time values
    std::tm tm = {};

    // Create std::istringstream objects for parsing the date and time strings
    std::istringstream dateStream(dateStr);
    std::istringstream timeStream(timeStr);
    // Variable to store the delimiter character between date and time components
    char delimiter;

    // Parse the date
    dateStream >> tm.tm_mon >> delimiter >> tm.tm_mday >> delimiter >> tm.tm_year;
    tm.tm_year -= 1900; // Year since 1900
    tm.tm_mon -= 1; // Month [0, 11]

    // Parse the time
    timeStream >> tm.tm_hour >> delimiter >> tm.tm_min;
    
    // Convert tm to time_t, then to time_point
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;
}
