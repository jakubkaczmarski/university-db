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

void Student::print() {
  std::cout<<"Indeks:   "<<getIndex()<<std::endl;
  std::cout<<"Imię:     "<<getName()<<std::endl;
  std::cout<<"Nazwisko: "<<getSurname()<<std::endl;
  std::cout<<"Adres:    "<<getAddress()<<std::endl;
  std::cout<<"Pesel:    "<<getPesel()<<std::endl;
  std::cout<<"Płeć:     "<<(getSex() == Gender::Female ? "Kobieta" : "Mężczyzna")
            <<std::endl;
  std::cout<<"----------------------------------\n";
}
size_t Student::getIndex() {
  return index_;
}
