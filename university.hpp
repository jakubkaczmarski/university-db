#pragma once
#include "person.hpp"
#include "student.hpp"
#include <vector>


class University {
public:
    University() = default;
    University(const std::vector<Person*> &persons);
    void addStudent(Student *);
    void removeStudents();
    void printAllDatabase();
    void saveRecords(const std::string &filename);
    void loadRecords(const std::string &filename);
    void searchBySurname(std::string surname);
    void searchByPesel(int64_t pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteByIndex(size_t index);

    auto begin() { return students_.begin(); }
    auto end() { return students_.end(); }

    std::vector<Person *> getStudents() const;
    void clearStudents();

private:
    std::vector<Person *> students_;
};