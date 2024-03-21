// CSVSearcher.cpp
#include "CSVSearcher.h"
#include <iostream>
#include <fstream>

// Method to read CSV and return the data
std::vector<std::vector<std::string>> CSVSearcher::readCSV(const std::string &filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return data;
    }

    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        data.push_back(split(line, ','));
    }

    file.close();
    return data;
}
// Method to split a string by a delimiter and return a vector
std::vector<std::string> CSVSearcher::split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    for (char ch : s)
    {
        if (ch != delimiter)
        {
            token += ch;
        }
        else
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Method to search the CSV file for a specific term within a given category
void CSVSearcher::searchInCSV(const std::string &filename, const std::string &searchTerm, const std::string &category)
{
    std::ifstream file(filename);
    std::string line;
    bool found = false;
    int columnIndex = -1; // Placeholder for column index

    if (!file.is_open())
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return;
    }

    if (getline(file, line))
    {
        std::vector<std::string> headers = split(line, ',');
        for (size_t i = 0; i < headers.size(); ++i)
        {
            if (headers[i] == category)
            {
                columnIndex = i; // Set the column index to the current position 'i'
                break;           // Exit the loop since we found the matching column
            }
        }
    }

    if (columnIndex == -1)
    {
        std::cerr << "Category '" << category << "' not found in the CSV headers." << std::endl;
        return;
    }

    while (getline(file, line))
    {
        std::vector<std::string> tokens = split(line, ',');
        if (static_cast<size_t>(columnIndex) < tokens.size() && tokens[columnIndex].find(searchTerm) != std::string::npos)
        {
            std::cout << "Found: " << line << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Search term '" << searchTerm << "' not found in the category '" << category << "'." << std::endl;
    }

    file.close();
}
