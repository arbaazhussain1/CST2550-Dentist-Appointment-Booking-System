// CSVSearcher.cpp
#include "CSVSearcher.h" // Include the header file for the CSVSearcher class
#include <iostream>
#include <fstream>

// Method to read CSV and return the data
std::vector<std::vector<std::string>> CSVSearcher::readCSV(const std::string &filename) {
    std::vector<std::vector<std::string>> data; // Vector to store the CSV data
    std::ifstream file(filename); // Open the CSV file for reading
    std::string line; // String to store each line of the CSV file

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl; // Print error message if file cannot be opened
        return data; // Return empty data vector
    }

    // Skip the header
    std::getline(file, line);

    // Read each line from the file and split it into tokens
    while (std::getline(file, line)) {
        data.push_back(split(line, ',')); // Push the tokens into the data vector
    }

    file.close(); // Close the file
    return data; // Return the CSV data
}
// Method to split a string by a delimiter and return a vector
std::vector<std::string> CSVSearcher::split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens; // Vector to store the tokens
    std::string token; // String to store each token
    // Iterate through each character in the input string
    for (char ch : s)
    {
        // Check if the character is not the delimiter
        if (ch != delimiter)
        {
            token += ch;  // Append the character to the current token
        }
        else
        {
            // If the character is the delimiter, push the current token into the vector
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear(); // Clear the token string
            }
        }
    }
    // Push the remaining token into the vector if it's not empty
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens; // Return the vector of tokens
}

// Method to search the CSV file for a specific term within a given category
void CSVSearcher::searchInCSV(const std::string &filename, const std::string &searchTerm, const std::string &category)
{
    std::ifstream file(filename); // Open the CSV file for reading
    std::string line; // String to store each line of the CSV file
    bool found = false; // Flag to indicate if the search term is found
    int columnIndex = -1; // Placeholder for column index

    // Check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl; // Print error message if file cannot be opened
        return;
    }

    // Read the header line and find the index of the specified category
    if (getline(file, line))
    {
        std::vector<std::string> headers = split(line, ','); // Split the header line into column headers
        // Iterate through the column headers to find the index of the specified category
        for (size_t i = 0; i < headers.size(); ++i)
        {
            if (headers[i] == category)
            {
                columnIndex = i; // Set the column index to the current position 'i'
                break;           // Exit the loop since we found the matching column
            }
        }
    }

    // Check if the specified category was found in the CSV headers
    if (columnIndex == -1)
    {
        std::cerr << "Category '" << category << "' not found in the CSV headers." << std::endl; // Print error message
        return;
    }

    // Iterate through each line of the file and search for the term within the specified category
    while (getline(file, line))
    {
        std::vector<std::string> tokens = split(line, ','); // Split the line into tokens
        // Check if the column index is within the range of tokens and if the search term is found
        if (static_cast<size_t>(columnIndex) < tokens.size() && tokens[columnIndex].find(searchTerm) != std::string::npos)
        {
            std::cout << "Found: " << line << std::endl; // Print the line containing the search term
            found = true; // Set the found flag to true
        }
    }
    // If the search term is not found, print a message
    if (!found)
    {
        std::cout << "Search term '" << searchTerm << "' not found in the category '" << category << "'." << std::endl;
    }

    file.close(); // Close the file
}
