#pragma once
#include "person.hpp"
#include "student.hpp"
#include <vector>


class University {
public:
    University() = default;
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
    auto erase(const std::vector<Person *>::iterator& it) { return students_.erase(it); }
    std::vector<Person *> getStudents() const;
    void clearStudents();

private:
    std::vector<Person *> students_;
};