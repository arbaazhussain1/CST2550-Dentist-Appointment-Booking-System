#include <iostream>
#include "CSV_Reader.h"
#include "Print_Functions.h"

//Function for getting lines as inputs while ignoring commas as delimiters if they are withing double quotation marks.
void CSV_Reader::getLineIgnoringQuotes(std::istream& input, std::string& result) {

    char delimiter = ','; // Delimiter for CSV files
    char character = input.get(); // Get the first character from the input stream
    bool inQuotes = false; // Flag to track if the current character is within double quotation marks

    // Loop until either the delimiter is found or the end of the line is reached
    while (character != delimiter || inQuotes) {
        if (character == '"') {
            inQuotes = !inQuotes; // Toggle the inQuotes flag when encountering double quotation marks
        } else if (character == delimiter && !inQuotes) {
            return; // Return if the delimiter is found and not within double quotation marks
        } else {
            result += character; // Append the character to the result string
        }
        character = input.get(); // Get the next character from the input stream
    }
}

/*Functions for reading the data from the CSV files,
 based on the code from this video: https://www.youtube.com/watch?v=NFvxA-57LLA*/
void CSV_Reader::readDentistsFile() {

  std::string line = "";

    // Read and discard the header line
    std::getline(dentistsFile, line);
    line = "";

    // Read each line from the dentists CSV file
    while (getline(dentistsFile, line)) {

    // Variables to store data for a dentist
    std::string dentistID;
    std::string title;
    std::string firstName;
    std::string surname;
    std::string address;
    std::string email;
    std::string salary;

    std::stringstream inputString(line); // Convert the line to a stringstream

    // Extract data from the line while ignoring commas within double quotation marks
    getLineIgnoringQuotes(inputString, dentistID);
    getLineIgnoringQuotes(inputString, title);
    getLineIgnoringQuotes(inputString, firstName);
    getLineIgnoringQuotes(inputString, surname);
    getLineIgnoringQuotes(inputString, address);
    getLineIgnoringQuotes(inputString, email);
    std::getline(inputString, salary, ' '); // Get the salary data

    // Create a new Dentist object with the extracted data and add it to the data object
    Dentist newDentist(title, firstName, surname, address, email, stoi(dentistID), stoi(salary));
    data->addDentist(newDentist);
    
    line = ""; // Clear the line for the next iteration
  }
  
}

// Similar functions for reading patients, rooms, and appointments files...

// Function to prompt the user for file selection and read data from selected files
void CSV_Reader::readPatientsFile() {

  std::string line = ""; // Initialize user input string
  
  getline(patientsFile, line); // Discard the header line
  line = ""; // Reset line string

    // Read each line from the patients CSV file
    while (getline(patientsFile, line)) {

    // Variables to store data for a patient
    std::string patientID;
    std::string title;
    std::string firstName;
    std::string surname;
    std::string address;
    std::string email;

    std::stringstream inputString(line); // Convert the line to a stringstream

    // Extract data from the line while ignoring commas within double quotation marks
    getLineIgnoringQuotes(inputString, patientID);
    getLineIgnoringQuotes(inputString, title);
    getLineIgnoringQuotes(inputString, firstName);
    getLineIgnoringQuotes(inputString, surname);
    getLineIgnoringQuotes(inputString, address);
    std::getline(inputString, email, ' ');  // Get the email data

    // Create a new Patient object with the extracted data and add it to the data object
    Patient newPatient(title, firstName, surname, address, email, stoi(patientID));
    data->addPatient(newPatient);
    
    line = ""; // Clear the line for the next iteration
  }
  
}

// Function to read room data from a CSV file
void CSV_Reader::readRoomsFile() {

  std::string line = ""; // Initialize line string
  
  getline(roomsFile, line); // Discard the header line
  line = ""; // Reset line string

    // Read each line from the rooms CSV file
    while (getline(roomsFile, line)) {

    std::string roomID;

    std::stringstream inputString(line); // Convert the line to a stringstream

    std::getline(inputString, roomID, ' '); // Extract room ID from the line

    // Create a new Room object with the extracted room ID and add it to the data object
    Room newRoom(stoi(roomID));
    data->addRoom(newRoom);
    
    line = ""; // Clear the line for the next iteration
  }
  
}

// Function to read appointment data from a CSV file
void CSV_Reader::readAppointmentsFile() {

  std::string line = ""; // Initialize line string
  
  getline(appointmentsFile, line); // Discard the header line
  line = ""; // Reset line string

    // Read each line from the appointments CSV file
    while (getline(appointmentsFile, line)) {

    // Variables to store data for a appointments
    std::string appointmentID;
    std::string roomID;
    std::string dentistID;
    std::string patientID;
    std::string time;

    std::stringstream inputString(line); // Convert the line to a stringstream

    // Extract data from the line while ignoring commas within double quotation marks
    getLineIgnoringQuotes(inputString, appointmentID);
    getLineIgnoringQuotes(inputString, roomID);
    getLineIgnoringQuotes(inputString, dentistID);
    getLineIgnoringQuotes(inputString, patientID);
    std::getline(inputString, time, ' '); // Get the time data

    unsigned long int parsedTime = stoi(time);
    Room* roomPtr = data->getRoom(stoi(roomID) - 1);
    Dentist* dentistPtr = data->getDentist(stoi(dentistID) - 1);
    Patient* patientPtr = nullptr;

    std::chrono::system_clock::time_point chronoTime = std::chrono::system_clock::from_time_t(parsedTime);

      // Create a new Appointment object with the extracted data and add it to the data object
      if (stoi(patientID) != 0) {
      patientPtr = data->getPatient(std::stoi(patientID) - 1);
      Appointment newAppointment(stoi(appointmentID), roomPtr, chronoTime, dentistPtr, patientPtr);
      data->addAppointment(newAppointment);
    } else {
      Appointment newAppointment(stoi(appointmentID), roomPtr, chronoTime, dentistPtr);
      data->addAppointment(newAppointment);
    }

    // Clear the line for the next iteration
    line = "";
  }
  
}

// Function to prompt the user for file selection and read data from selected files
void CSV_Reader::fileSelection() {

  std::string userInput = ""; // Initialize user input string

  bool valid = false; // Flag to track if user input is valid
  
  std::cin  >> userInput; // Prompt the user for input

    // Check user input for default or custom file selection
    if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y") {
    userInput = ""; // Reset user input
    // Set default file names
    dentistsFileName = defaultDentistsFileName;
    patientsFileName = defaultPatientsFileName;
    roomsFileName = defaultRoomsFileName;
    appointmentsFileName = defaultAppointmentsFileName;
    valid = true; // Set input validity flag
  } else if (userInput == "No" || userInput == "no" || userInput == "N" || userInput == "n") {
    userInput = "";  // Reset user input
    // Prompt user for custom file names
    println("Enter the name of the .csv file for the dentists.");
    std::cin  >> dentistsFileName;
    println("Enter the name of the .csv file for the patients.");
    std::cin  >> patientsFileName;
    println("Enter the name of the .csv file for the rooms.");
    std::cin  >> roomsFileName;
    println("Enter the name of the .csv file for the appointments.");
    std::cin  >> appointmentsFileName;
    valid = true; // Set input validity flag
  } else {
    println("Invalid input. Enter either 'yes' or 'no'.");
    userInput = ""; // Reset user input
    fileSelection(); // Recursive call to prompt user again
  }

    // If user input is valid
    if (valid) {
    // Open CSV files
    dentistsFile.open(dentistsFileName);
    if (dentistsFile.fail()){
	std::cout << "Error, " << dentistsFileName << " does not exist." << std::endl;
	exit(1);
      }
    patientsFile.open(patientsFileName);
    if (patientsFile.fail()){
	std::cout << "Error, " << patientsFileName << " does not exist." << std::endl;
	exit(1);
      }
    roomsFile.open(roomsFileName);
    if (roomsFile.fail()){
	std::cout << "Error, " << roomsFileName << " does not exist." << std::endl;
	exit(1);
      }
    appointmentsFile.open(appointmentsFileName);
    if (appointmentsFile.fail()){
	std::cout << "Error, " << appointmentsFileName << " does not exist." << std::endl;
	exit(1);
      }
    // Read data from CSV files
    readDentistsFile();
    readPatientsFile();
    readRoomsFile();
    readAppointmentsFile();
    println("Welcome to the dentist programme. Select command.");
  }

}
