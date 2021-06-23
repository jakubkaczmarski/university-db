#pragma once
#include "person.hpp"
#include "student.hpp"
#include <vector>


class University {
public:
    University() = default;
    University(const std::vector<Person*> &persons);

    // ~University() { clearStudents(); }

    void addStudent(Student *);
    void removeStudents(const size_t& index);
    void printAllDatabase();
    void saveRecords(const std::string &filename);
    void loadRecords(const std::string &filename);
    void searchBySurname(std::string surname);
    void searchByPesel(int64_t pesel);
    void sortByPesel();
    void sortBySurname();

    auto begin() { return students_.begin(); }
    auto end() { return students_.end(); }
    auto erase(const std::vector<Person *>::iterator& it) { auto r = students_.erase(it); students_.shrink_to_fit();}
    void clearStudents();

private:
    std::vector<Person *> students_;
};