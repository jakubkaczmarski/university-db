#include "student.hpp"
Student::Student(const std::string &name,
                 const std::string &surname,
                 const std::string &address,
                 size_t index,
                 int64_t pesel,
                 Gender sex)
  : Person(name, surname, address, pesel, sex), index_(index)
{
       
}

size_t Student::getIndex() {
       return index_;
    }
