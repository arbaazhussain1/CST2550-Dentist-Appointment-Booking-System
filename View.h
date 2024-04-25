#ifndef VIEW_H
#define VIEW_H

#include "Data.h" // Include necessary header file for Data class

class View {
 private:
  Data* data;
 public:
    // Constructor to initialize with Data object
    View(Data* d) {
    data = d;
  }
  // Methods to print various entities
  void printDentists();
  void printPatients();
  void printRooms();
  void printAppointments();
  void printSortedAppointments();
  void printDoctorsAvailableAppointments(int dentistId);
  void printAllAppointmentsForDentistAndPatient(int dentistId, int patientId);
};

#endif // VIEW_H
