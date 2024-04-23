#include <iostream>
#include <vector>
#include <chrono>
#include "QuickSort.h"
#include "Dentist.h"
#include "Patient.h"
#include "CSVSearcher.h"
#include "Appointment.h"
#include "AppointmentDisplay.h"
#include "AppointmentManager.h"
#include "DentistManager.h"
#include "DateTimeUtils.h"
#include <sstream>
#include <ctime>

int main()
{
    // std::vector<Appointment> appointments;

    // // add dentist and patient instance
    // Dentist drSmith("Dr", "Smith", "Smith", "add", "emai", 101, 50000);
    // Patient johnDoe("Mr", "John", "Doe", "add", "emai", 202);

    // //CSVSearcher searcher;
    // DentistManager dentistManager;
    // AppointmentManager appointmentManager(dentistManager);

    // std::string filename = "dentist_office.csv";

    // // POPULATE APPOINTMENTS FROM CSV
    // //appointmentManager.populateAppointmentsFromCSV(filename, appointments);

    // // SEARCHING

    // // Example searching for a room
    // //searcher.searchInCSV(filename, "101", "Room");
    // // Example searching for a dentist by name
    // //searcher.searchInCSV(filename, "Dr. Smith", "Dentist");

    // // INTERFACE

    // bool running = true;
    // int choice;
    // while (running)
    // {
    //     std::cout << "Dental Clinic Management System\n";
    //     std::cout << "1. Display All Appointments\n";
    //     std::cout << "2. Assign Patient to Appointment\n";
    //     std::cout << "3. Exit\n";
    //     std::cout << "Enter your choice: ";
    //     std::cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
	//   //AppointmentDisplay::displayAppointments(appointments);
    //         break;
    //     case 2:
    //     {
    //         // TEMPORARY, NON DYNAMIC CODE TO ASSIGN PATIENT TO APPOINTMENT. WORKS FOR HARD CODED PATIENT.
    //         bool patientSet = false;
    //         for (auto &appointment : appointments)
    //         {
    //             if (appointment.getIsFree())
    //             {
    //                 appointment.setPatient(&johnDoe);
    //                 std::cout << "Patient " << johnDoe.getFirstName() << " assigned to an appointment.\n";
    //                 patientSet = true;
    //                 break;
    //             }
    //         }
    //         if (!patientSet)
    //         {
    //             std::cout << "No available appointments to assign.\n";
    //         }
    //     }
    //     break;
    //     case 3:
    //         running = false;
    //         std::cout << "Exiting system.\n";
    //         break;
    //     default:
    //         std::cout << "Invalid option, please try again.\n";
    //     }
    // }

    // return 0;
}
