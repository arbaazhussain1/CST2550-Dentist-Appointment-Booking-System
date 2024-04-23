// CSVSearcher.h
#ifndef CSVSEARCHER_H
#define CSVSEARCHER_H

#include <string>
#include <vector>

class CSVSearcher {
public:
    void searchInCSV(const std::string& filename, const std::string& searchTerm, const std::string& category);
    std::vector<std::vector<std::string>> readCSV(const std::string &filename);
private:
    std::vector<std::string> split(const std::string &s, char delimiter);
};

#endif // CSVSEARCHER_H
