#include "Person.h" // Include the header file defining the Person class

// Implementation of the setter and getter methods for the Person class

// Setter methods.

// Setter method for setting the title of the person.
void Person::setTitle(const std::string& t) {
    title = t;
}

// Setter method for setting the first name of the person.
void Person::setFirstName(const std::string& fn) {
    firstName = fn;
}

// Setter method for setting the surname of the person.
void Person::setSurname(const std::string& sn) {
    surname = sn;
}

// Setter method for setting the address of the person.
void Person::setAddress(const std::string& a) {
    address = a;
}

// Setter method for setting the email of the person.
void Person::setEmail(const std::string& e) {
    email = e;
}

// Getter methods.

// Getter method for retrieving the title of the person.
std::string Person::getTitle() const {
    return title;
}

// Getter method for retrieving the first name of the person.
std::string Person::getFirstName() const {
    return firstName;
}

// Getter method for retrieving the surname of the person.
std::string Person::getSurname() const {
    return surname;
}

// Getter method for retrieving the address of the person.
std::string Person::getAddress() const {
    return address;
}

// Getter method for retrieving the email of the person.
std::string Person::getEmail() const {
    return email;
}
