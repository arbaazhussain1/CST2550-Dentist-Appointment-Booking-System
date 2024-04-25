// CSVSearcher.h
#ifndef CSVSEARCHER_H
#define CSVSEARCHER_H

#include <string>
#include <vector>

class CSVSearcher {
public:
    // Method to search the CSV file for a specific term within a given category
    void searchInCSV(const std::string& filename, const std::string& searchTerm, const std::string& category);
    // Method to read CSV and return the data
    std::vector<std::vector<std::string>> readCSV(const std::string &filename);
private:
    // Method to split a string by a delimiter and return a vector
    std::vector<std::string> split(const std::string &s, char delimiter);
};

#endif // CSVSEARCHER_H
