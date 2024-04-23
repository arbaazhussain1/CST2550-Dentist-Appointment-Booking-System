#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include "Appointment.h"
#include "Print_Functions.h"
#include <chrono>

//Declarations.

const auto now = std::chrono::system_clock::now();

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
