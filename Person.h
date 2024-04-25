#ifndef PERSON_H
#define PERSON_H

#include <string> // Include the string library for string manipulation

class Person {
 private:
  std::string title; // Title of the person
  std::string firstName; // First name of the person
  std::string surname; // Surname of the person
  std::string address; // Address of the person
  std::string email;  // Email of the person
  
 public:
    // Constructor to initialize a Person object with provided details
    Person(const std::string& t, const std::string& fn, const std::string& sn, const std::string& a, const std::string& e) {
    setTitle(t); // Set the title
    setFirstName(fn); // Set the first name
    setSurname(sn); // Set the surname
    setAddress(a); // Set the address
    setEmail(e); // Set the email
  }

  // Public setter methods to set various attributes of the person
  void setTitle(const std::string& t); // Setter method for title
  void setFirstName(const std::string& fn); // Setter method for first name
  void setSurname(const std::string& sn); // Setter method for surname
  void setAddress(const std::string& a); // Setter method for address
  void setEmail(const std::string& e); // Setter method for email

  // Public getter methods to retrieve various attributes of the person
  std::string getTitle() const; // Getter method for title
  std::string getFirstName() const; // Getter method for first name
  std::string getSurname() const; // Getter method for surname
  std::string getAddress() const; // Getter method for address
  std::string getEmail() const; // Getter method for email
};

#endif // PERSON_H
