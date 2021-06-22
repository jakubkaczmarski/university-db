#pragma once
#include <string>
enum class Gender { Male, Female };

class Person {
public:
  Person() = default;
  Person(std::string  name,
         std::string  surname,
         std::string  address,
         int64_t pesel = 0,
         Gender sex = Gender::Female);
  virtual ~Person() = default;

  std::string getName() const;
  std::string getSurname() const;
  std::string getAddress() const;
  int64_t getPesel() const;
  Gender getSex() const;

  virtual void print() = 0;

  bool peselIsCorrect();
private:
  std::string name_;
  std::string surname_;
  std::string address_;
  int64_t pesel_;
  Gender sex_;
};