#include "Person.h"

//Setter methods.

void Person::setTitle(const std::string& t) {
    title = t;
}

void Person::setFirstName(const std::string& fn) {
    firstName = fn;
}

void Person::setSurname(const std::string& sn) {
    surname = sn;
}

void Person::setAddress(const std::string& a) {
    address = a;
}

void Person::setEmail(const std::string& e) {
    email = e;
}

//Getter methods.

std::string Person::getTitle() const {
    return title;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getSurname() const {
    return surname;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getEmail() const {
    return email;
}
