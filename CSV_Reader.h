#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <sstream>
#include "Data.h"
#include "Dentist.h" 
#include "Patient.h"
#include "Appointment.h"

class CSV_Reader {
 private:
  Data* data;
  
  std::ifstream dentistsFile;
  std::ifstream patientsFile;
  std::ifstream roomsFile;
  std::ifstream appointmentsFile;
  
  std::ofstream dentistsFileWrite;
  std::ofstream patientsFileWrite;
  std::ofstream roomsFileWrite;
  std::ofstream appointmentsFileWrite;
  
  std::string dentistsFileName;
  std::string patientsFileName;
  std::string roomsFileName;
  std::string appointmentsFileName;
  
  const std::string defaultDentistsFileName = "dentists.csv";
  const std::string defaultPatientsFileName = "patients.csv";
  const std::string defaultRoomsFileName = "rooms.csv";
  const std::string defaultAppointmentsFileName = "appointments.csv";
 public:
  CSV_Reader(Data* d) {
    data = d;
  }
  void getLineIgnoringQuotes(std::istream& input, std::string& result);
  void readDentistsFile();
  void readPatientsFile();
  void readRoomsFile();
  void readAppointmentsFile();
  void fileSelection();
};

#endif
