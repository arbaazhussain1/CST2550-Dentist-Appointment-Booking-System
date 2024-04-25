#include "PatientManager.h"
#include "Print_Functions.h"
#include <iostream>
#include <fstream>
#include <vector>

// Function to get input from the user with a prompt
bool getInput(const std::string& prompt, std::string& input) {
    print(prompt);  // Print the prompt
    if (std::cin.peek() == '\n') { // Check if there are any characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters in the input buffer
    } 
    std::getline(std::cin, input); // Get input from the user
    if (input == "0") { // Check if input is "0", indicating cancellation
        println("Operation cancelled by user.");
        return false; // Return false to indicate cancellation
    }
    return true; // Return true if input is not "0"
}

// Method to add a new patient
void PatientManager::addNewPatient() {
    std::string title, firstName, surname, address, email;
    int patientId = data->getMaxPatientID() + 1; // Generate patient ID

    std::cout << "Adding new patient with ID: " << patientId << std::endl;

    // Get input for patient details
    if (!getInput("Enter Title: (Or 0 to cancel) ", title) ||
        !getInput("Enter First Name: (Or 0 to cancel) ", firstName) ||
        !getInput("Enter Surname: (Or 0 to cancel) ", surname) ||
        !getInput("Enter Address: (Or 0 to cancel) ", address) ||
        !getInput("Enter Email: (Or 0 to cancel) ", email)) {
        return; // Return if user cancels the operation
    }

    // Append '.' to title if it's missing
    if (title.back() != '.') {
        title += '.';
    }

    // Create a new patient object
    Patient newPatient(title, firstName, surname, address, email, patientId);
    data->addPatient(newPatient); // Add the new patient to the data manager
    savePatientsToCSV(); // Save the updated list of patients to CSV file
}

// Method to save the list of patients to a CSV file
void PatientManager::savePatientsToCSV() {
    std::ofstream outFile("patients.csv"); // Open output file
    outFile << "Patient ID,Title,First Name,Surname,Address,Email\n";  // Write header row

    const std::vector<Patient>& patients = data->getPatients(); // Get list of patients
    // Write patient details to the CSV file
    for (const auto& patient : patients) {
        outFile << patient.getPatientID() << ","
                << patient.getTitle() << ","
                << patient.getFirstName() << ","
                << patient.getSurname() << ","
                << patient.getAddress() << ","
                << patient.getEmail() << "\n";
    }

    outFile.close();  // Close the output file
}
