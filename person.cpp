#include "person.hpp"
#include "validation.hpp"

Person::Person(std::string name,
       std::string surname,
       std::string address,
       int64_t pesel,
       Gender sex)
: name_(std::move(name)), surname_(std::move(surname)), address_(std::move(address)), pesel_(pesel), sex_(sex)
{
}

std::string Person::getName() const {
  return name_;
}

std::string Person::getSurname() const {
  return surname_;
}

std::string Person::getAddress() const {
  return address_;
}
int64_t Person::getPesel() const {
  return pesel_;
}
Gender Person::getSex() const {
  return sex_;
}
bool Person::peselIsCorrect() {
    std::unique_ptr<Validation> validation(new Validation(pesel_));
    validation->execute();
    return validation->isCorrect();
}
