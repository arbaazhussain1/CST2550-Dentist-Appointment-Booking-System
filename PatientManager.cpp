#include "PatientManager.h"
#include "Print_Functions.h"
#include <iostream>
#include <fstream>
#include <vector>

bool getInput(const std::string& prompt, std::string& input) {
    print(prompt);
    if (std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    std::getline(std::cin, input);
    if (input == "0") {
        println("Operation cancelled by user.");
        return false;
    }
    return true;
}

void PatientManager::addNewPatient() {
    std::string title, firstName, surname, address, email;
    int patientId = data->getMaxPatientID() + 1;

    std::cout << "Adding new patient with ID: " << patientId << std::endl;

    if (!getInput("Enter Title: (Or 0 to cancel) ", title) ||
        !getInput("Enter First Name: (Or 0 to cancel) ", firstName) ||
        !getInput("Enter Surname: (Or 0 to cancel) ", surname) ||
        !getInput("Enter Address: (Or 0 to cancel) ", address) ||
        !getInput("Enter Email: (Or 0 to cancel) ", email)) {
        return;
    }

    if (title.back() != '.') {
        title += '.';
    }
    Patient newPatient(title, firstName, surname, address, email, patientId);
    data->addPatient(newPatient);
    savePatientsToCSV();
}

void PatientManager::savePatientsToCSV() {
    std::ofstream outFile("patients.csv");
    outFile << "Patient ID,Title,First Name,Surname,Address,Email\n";

    const std::vector<Patient>& patients = data->getPatients();
    for (const auto& patient : patients) {
        outFile << patient.getPatientID() << ","
                << patient.getTitle() << ","
                << patient.getFirstName() << ","
                << patient.getSurname() << ","
                << patient.getAddress() << ","
                << patient.getEmail() << "\n";
    }

    outFile.close();
}
