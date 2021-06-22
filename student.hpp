#pragma once
#include "iostream"
#include "person.hpp"
#include "string"
#include <memory>
class Student : public Person {
public:
  Student(
      const std::string& name,
      const std::string& surname,
      const std::string& address,
      size_t index = 0,
      int64_t pesel = 0,
      Gender sex = Gender::Female
      );

  void print() override;
  size_t getIndex() override;
  ~Student() = default;
private:
    size_t index_;
};