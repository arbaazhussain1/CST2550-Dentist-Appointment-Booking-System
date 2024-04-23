#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
 private:
  std::string title;
  std::string firstName;
  std::string surname;
  std::string address;
  std::string email;
  
 public:
  Person(const std::string& t, const std::string& fn, const std::string& sn, const std::string& a, const std::string& e) {
    setTitle(t);
    setFirstName(fn);
    setSurname(sn);
    setAddress(a);
    setEmail(e);
  }

  //Public setter methods.
  void setTitle(const std::string& t);
  void setFirstName(const std::string& fn);
  void setSurname(const std::string& sn);
  void setAddress(const std::string& a);
  void setEmail(const std::string& e);

  //Public getter methods.
  std::string getTitle() const;
  std::string getFirstName() const;
  std::string getSurname() const;
  std::string getAddress() const;
  std::string getEmail() const;
};

#endif // PERSON_H
