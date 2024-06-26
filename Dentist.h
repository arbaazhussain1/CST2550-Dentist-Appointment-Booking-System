#ifndef DENTIST_H
#define DENTIST_H

#include "Person.h"

// The Dentist class inherits from the Person class
class Dentist : public Person {
private:
  int dentistID;
  int salary;

public:
    // Constructor with initialization list to initialize Person attributes and set dentist ID and salary
    Dentist(const std::string &t, const std::string &fn, const std::string &sn, const std::string &a, const std::string &e, int ID, int s) : Person(t, fn, sn, a, e)
  {
    setDentistID(ID);
    setSalary(s);
  }

  // Public setter methods.
  void setDentistID(int ID);
  void setSalary(int s);

  // Public getter methods.
  int getDentistID() const;
  int getSalary() const;
};

#endif // DENTIST_H
