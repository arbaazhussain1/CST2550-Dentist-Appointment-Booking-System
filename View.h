#ifndef VIEW_H
#define VIEW_H

#include "Data.h"

class View {
 private:
  Data* data;
 public:
  View(Data* d) {
    data = d;
  }
  void printDentists();
  void printPatients();
  void printRooms();
  void printAppointments();
  void printSortedAppointments();
  void printDoctorsAvailableAppointments(int dentistId);
  void printAllAppointmentsForDentistAndPatient(int dentistId, int patientId);
};

#endif
