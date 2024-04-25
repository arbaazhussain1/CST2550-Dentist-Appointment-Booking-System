#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include "Appointment.h"
#include "Print_Functions.h"
#include <chrono>
#include "AppointmentDisplay.h"
#include "DentistManager.h"
#include "AppointmentManager.h"
#include <fstream>
#include "DateTimeUtils.h"
#include "CSVSearcher.h"

// This line defines that Catch2 should generate a main function for the test suite.
// This macro must be defined once and only once in a single translation unit.

//Declarations.

const auto now = std::chrono::system_clock::now();

// Creating instances of Dentist, Patient, Room, and Appointment for testing purposes.
Dentist dentist1("Dr.", "Andrew", "Brown", "address1", "email1", 1, 50000);
Dentist dentist2("Dr.", "Thomas", "Green", "address2", "email2", 2, 30000);
Dentist dentist3("Dr.", "Peter", "Yeoman", "address3", "email3", 3, 40000);

Patient patient1("Mr.", "John", "Smith", "address1", "email1", 1);
Patient patient2("Mr.", "Aaron", "Carter", "address2", "email2", 2);
Patient patient3("Mr.", "Brian", "Turner", "address3", "email3", 3);
Patient patient4("Mr.", "David", "Grey", "address4", "email4", 4);
Patient patient5("Mr.", "Gordon", "Pike", "address5", "email5", 5);

Room room1(1);
Room room2(2);
Room room3(3);

Appointment appointment1(1, &room1, now, &dentist1, &patient1);
Appointment appointment2(2, &room2, now, &dentist2, &patient2);
Appointment appointment3(3, &room3, now, &dentist3, &patient3);
Appointment appointment4(4, &room1, now, &dentist1, &patient4);
Appointment appointment5(5, &room2, now, &dentist2, &patient5);

//Test Cases.

// Testing Dentist class.
TEST_CASE("dentist1", "[dentist1]")
{
    REQUIRE(dentist1.getDentistID() == 1);
    REQUIRE(dentist1.getTitle() == "Dr.");
    REQUIRE(dentist1.getFirstName() == "Andrew");
    REQUIRE(dentist1.getSurname() == "Brown");
    REQUIRE(dentist1.getAddress() == "address1");
    REQUIRE(dentist1.getEmail() == "email1");
    REQUIRE(dentist1.getSalary() == 50000);
}

TEST_CASE("dentist2", "[dentist2]")
{
    REQUIRE(dentist2.getDentistID() == 2);
    REQUIRE(dentist2.getTitle() == "Dr.");
    REQUIRE(dentist2.getFirstName() == "Thomas");
    REQUIRE(dentist2.getSurname() == "Green");
    REQUIRE(dentist2.getAddress() == "address2");
    REQUIRE(dentist2.getEmail() == "email2");
    REQUIRE(dentist2.getSalary() == 30000);
}

TEST_CASE("dentist3", "[dentist3]")
{
    REQUIRE(dentist3.getDentistID() == 3);
    REQUIRE(dentist3.getTitle() == "Dr.");
    REQUIRE(dentist3.getFirstName() == "Peter");
    REQUIRE(dentist3.getSurname() == "Yeoman");
    REQUIRE(dentist3.getAddress() == "address3");
    REQUIRE(dentist3.getEmail() == "email3");
    REQUIRE(dentist3.getSalary() == 40000);
}


// Testing Patient class initialization.
TEST_CASE("Patient Initialization") {
    SECTION("Patient1 Initialization") {
        REQUIRE(patient1.getPatientID() == 1);
        REQUIRE(patient1.getTitle() == "Mr.");
        REQUIRE(patient1.getFirstName() == "John");
        REQUIRE(patient1.getSurname() == "Smith");
        REQUIRE(patient1.getAddress() == "address1");
        REQUIRE(patient1.getEmail() == "email1");
    }

    SECTION("Patient2 Initialization") {
        REQUIRE(patient2.getPatientID() == 2);
        REQUIRE(patient2.getTitle() == "Mr.");
        REQUIRE(patient2.getFirstName() == "Aaron");
        REQUIRE(patient2.getSurname() == "Carter");
        REQUIRE(patient2.getAddress() == "address2");
        REQUIRE(patient2.getEmail() == "email2");
    }
}

// Testing Appointment class initialization.
TEST_CASE("Appointment Initialization") {
    SECTION("Appointment1 Initialization") {
        REQUIRE(appointment1.getID() == 1);
        REQUIRE(appointment1.getRoom() == &room1);
        REQUIRE(appointment1.getDate() == now);
        REQUIRE(appointment1.getDentist() == &dentist1);
        REQUIRE(appointment1.getPatient() == &patient1);
    }

    SECTION("Appointment2 Initialization") {
        REQUIRE(appointment2.getID() == 2);
        REQUIRE(appointment2.getRoom() == &room2);
        REQUIRE(appointment2.getDate() == now);
        REQUIRE(appointment2.getDentist() == &dentist2);
        REQUIRE(appointment2.getPatient() == &patient2);
    }


}

// Testing invalid initialization of Dentist class.
TEST_CASE("Invalid Dentist Initialization") {
    Dentist invalidDentist("", "", "", "", "", 0, 0);  // Creating a dentist with invalid data
    REQUIRE(invalidDentist.getDentistID() == 0);      // Expected to fail
    REQUIRE(invalidDentist.getSalary() == 0);         // Expected to fail

}

// Testing invalid initialization of Patient class.
TEST_CASE("Invalid Patient Initialization") {
    Patient invalidPatient("", "", "", "", "", 0);  // Creating a patient with invalid data
    REQUIRE(invalidPatient.getPatientID() == 0);    // Expected to fail

}

// Testing invalid initialization of Appointment class.
TEST_CASE("Invalid Appointment Initialization") {
    Room invalidRoom(0);  // Creating a room with an invalid ID
    Dentist invalidDentist("", "", "", "", "", 0, 0);
    Patient invalidPatient("", "", "", "", "", 0);
    Appointment invalidAppointment(0, &invalidRoom, now, &invalidDentist, &invalidPatient);  // Creating an appointment with invalid data
    REQUIRE(invalidAppointment.getID() == 0);        // Expected to fail
    REQUIRE(invalidAppointment.getRoom() == nullptr); // Expected to fail
    REQUIRE(invalidAppointment.getDentist() == nullptr); // Expected to fail
    REQUIRE(invalidAppointment.getPatient() == nullptr); // Expected to fail

}

// Testing boundary conditions for Dentist salary.
TEST_CASE("Boundary Conditions for Dentist Salary") {
    REQUIRE(dentist1.getSalary() > 0);   // Ensure salary is positive
    REQUIRE(dentist2.getSalary() > 0);   // Ensure salary is positive
    REQUIRE(dentist3.getSalary() > 0);   // Ensure salary is positive

}

// Testing boundary conditions for Patient ID.
TEST_CASE("Boundary Conditions for Patient ID") {
    REQUIRE(patient1.getPatientID() > 0);   // Ensure patient ID is positive
    REQUIRE(patient2.getPatientID() > 0);   // Ensure patient ID is positive

}

// Testing boundary conditions for Appointment ID.
TEST_CASE("Boundary Conditions for Appointment ID") {
    REQUIRE(appointment1.getID() > 0);   // Ensure appointment ID is positive
    REQUIRE(appointment2.getID() > 0);   // Ensure appointment ID is positive

}
