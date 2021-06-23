#include "university.hpp"
#include "student.hpp"
#include <memory>

int main() {
    std::unique_ptr<University> university(new University());
    // university->loadRecords("university.json");
    university->printAllDatabase();
    // Printing all database.

    std::cout << "Adding new students to database.\n";
    university->addStudent(new Student("Adam", "Mickiewicz", "Zaosie", 100044, 98122400010, Gender::Male));
    university->addStudent(new Student("Robert", "Makłowicz", "Kraków", 215647, 63081209379, Gender::Male));
    university->addStudent(new Student("Zofia", "Zofińska", "Lublin", 759391, 51020634982, Gender::Female));
    university->saveRecords("university.json");
    // Adding new students to database.

    std::cout << "Searching by surname and by pesel number.\n";
    university->searchBySurname("Mickiewicz");
    university->searchByPesel(75111209379);
    // Searching by surname and by pesel number.

    std::cout << "Sorting by surname.\n";
    university->sortBySurname();
    university->printAllDatabase();
    std::cout << "Sorting by pesel number.\n";
    university->sortByPesel();
    university->printAllDatabase();
    // Sorting by surname and by pesel number.

    std::cout << "Removing students by index and saving them.\n";
    university->removeStudents(759391);
    university->saveRecords("university.json");
    university->printAllDatabase();
    // Removing students by index.

    std::cout << "Removing students from database.\n";
    university->clearStudents();
     // Removing students from database.

    return 0;
}
