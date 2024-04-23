#include <iostream>
#include "CSV_Reader.h"
#include "Print_Functions.h"

//Function for getting lines as inputs while ignoring commas as delimiters if they are withing double quotation marks.

void CSV_Reader::getLineIgnoringQuotes(std::istream& input, std::string& result) {

    char delimiter = ',';
    char character = input.get();
    bool inQuotes = false;

    while (character != delimiter || inQuotes) {
        if (character == '"') {
            inQuotes = !inQuotes;
        } else if (character == delimiter && !inQuotes) {
            return;
        } else {
            result += character;
        }
        character = input.get();
    }
}

/*Functions for reading the data from the CSV files,
 based on the code from this video: https://www.youtube.com/watch?v=NFvxA-57LLA*/

void CSV_Reader::readDentistsFile() {

  std::string line = "";
  
  std::getline(dentistsFile, line);
  line = "";
  
  while (getline(dentistsFile, line)) {

    std::string dentistID;
    std::string title;
    std::string firstName;
    std::string surname;
    std::string address;
    std::string email;
    std::string salary;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, dentistID);
    getLineIgnoringQuotes(inputString, title);
    getLineIgnoringQuotes(inputString, firstName);
    getLineIgnoringQuotes(inputString, surname);
    getLineIgnoringQuotes(inputString, address);
    getLineIgnoringQuotes(inputString, email);
    std::getline(inputString, salary, ' ');

    Dentist newDentist(title, firstName, surname, address, email, stoi(dentistID), stoi(salary));
    data->addDentist(newDentist);
    
    line = "";
  }
  
}

void CSV_Reader::readPatientsFile() {

  std::string line = "";
  
  getline(patientsFile, line);
  line = "";
  
  while (getline(patientsFile, line)) {

    std::string patientID;
    std::string title;
    std::string firstName;
    std::string surname;
    std::string address;
    std::string email;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, patientID);
    getLineIgnoringQuotes(inputString, title);
    getLineIgnoringQuotes(inputString, firstName);
    getLineIgnoringQuotes(inputString, surname);
    getLineIgnoringQuotes(inputString, address);
    std::getline(inputString, email, ' ');

    Patient newPatient(title, firstName, surname, address, email, stoi(patientID));
    data->addPatient(newPatient);
    
    line = "";
  }
  
}


void CSV_Reader::readRoomsFile() {

  std::string line = "";
  
  getline(roomsFile, line);
  line = "";
  
  while (getline(roomsFile, line)) {

    std::string roomID;

    std::stringstream inputString(line);

    std::getline(inputString, roomID, ' ');

    Room newRoom(stoi(roomID));
    data->addRoom(newRoom);
    
    line = "";
  }
  
}

void CSV_Reader::readAppointmentsFile() {

  std::string line = "";
  
  getline(appointmentsFile, line);
  line = "";
  
  while (getline(appointmentsFile, line)) {

    std::string appointmentID;
    std::string roomID;
    std::string dentistID;
    std::string patientID;
    std::string time;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, appointmentID);
    getLineIgnoringQuotes(inputString, roomID);
    getLineIgnoringQuotes(inputString, dentistID);
    getLineIgnoringQuotes(inputString, patientID);
    std::getline(inputString, time, ' ');

    unsigned long int parsedTime = stoi(time);
    Room* roomPtr = data->getRoom(stoi(roomID) - 1);
    Dentist* dentistPtr = data->getDentist(stoi(dentistID) - 1);
    Patient* patientPtr = nullptr;

    std::chrono::system_clock::time_point chronoTime = std::chrono::system_clock::from_time_t(parsedTime);

    if (stoi(patientID) != 0) {
      patientPtr = data->getPatient(std::stoi(patientID) - 1);
      Appointment newAppointment(stoi(appointmentID), roomPtr, chronoTime, dentistPtr, patientPtr);
      data->addAppointment(newAppointment);
    } else {
      Appointment newAppointment(stoi(appointmentID), roomPtr, chronoTime, dentistPtr);
      data->addAppointment(newAppointment);
    }

    //std::cout << data->getAppointment(0).getDentist()->getFirstName() << std::endl;
    line = "";
  }
  
}

void CSV_Reader::fileSelection() {

  std::string userInput = "";

  bool valid = false;
  
  std::cin  >> userInput;

  if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y") {
    userInput = "";
    dentistsFileName = defaultDentistsFileName;
    patientsFileName = defaultPatientsFileName;
    roomsFileName = defaultRoomsFileName;
    appointmentsFileName = defaultAppointmentsFileName;
    valid = true;
  } else if (userInput == "No" || userInput == "no" || userInput == "N" || userInput == "n") {
    userInput = "";
    println("Enter the name of the .csv file for the dentists.");
    std::cin  >> dentistsFileName;
    println("Enter the name of the .csv file for the patients.");
    std::cin  >> patientsFileName;
    println("Enter the name of the .csv file for the rooms.");
    std::cin  >> roomsFileName;
    println("Enter the name of the .csv file for the appointments.");
    std::cin  >> appointmentsFileName;
    valid = true;
  } else {
    println("Invalid input. Enter either 'yes' or 'no'.");
    userInput = "";
    fileSelection();
  }

  if (valid) {
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
    readDentistsFile();
    readPatientsFile();
    readRoomsFile();
    readAppointmentsFile();
    println("Welcome to the dentist programme. Select command.");
  }

}
