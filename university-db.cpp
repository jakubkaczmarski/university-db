#include "university.hpp"
#include <memory>

int main() {

    std::unique_ptr<University> university(new University());
    university->addStudent(new Student("Jan", "Kowalski", "Warszawa", 1001,
                                       22113355664, Gender::Male));
    university->addStudent(new Student("Anna", "Nowak", "Wrocław", 1002,
                                       12345678901, Gender::Female));
    university->addStudent(new Student("Andrzej", "Skowroński", "Gdańsk", 1003,
                                       11223344556, Gender::Male));
    university->saveRecords("university.json");

//    university->searchByPesel(12345678901);
//    university->searchBySurname("Kowalski");
    university->removeStudents(1003);
    university->printAllDatabase();

    return 0;
}