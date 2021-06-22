#include "print.hpp"
#include "person.hpp"
Print::Print(University *university)
    : Command(university) {}

void Print::execute() {
    for (auto it = university_->begin(); it != university_->end(); it++) {

        std::cout << "Indeks:   " << (*it)->getIndex() << std::endl;
        std::cout << "Imię:     " << (*it)->getName() << std::endl;
        std::cout << "Nazwisko: " << (*it)->getSurname() << std::endl;
        std::cout << "Adres:    " << (*it)->getAddress() << std::endl;
        std::cout << "Pesel:    " << (*it)->getPesel() << std::endl;
        std::cout << "Płeć:     " << ((*it)->getSex() == Gender::Female ? "Kobieta" : "Mężczyzna") << std::endl;
        std::cout << "----------------------------------\n";
    }
}

