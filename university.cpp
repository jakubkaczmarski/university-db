#include "university.hpp"
#include "delete.hpp"
#include "load.hpp"
#include "print.hpp"
#include "save.hpp"
#include "search.hpp"
#include "sort.hpp"
#include "student.hpp"
#include "remove.hpp"

#include <memory>
#include <utility>
University::University(const std::vector<Person *> &persons)
    : students_(persons) {
}

void University::printAllDatabase() {
    std::unique_ptr<Print> print(new Print(this));
    print->execute();
}
void University::loadRecords(const std::string &filename) {
    std::unique_ptr<Load> load(new Load(this, filename));

    load->execute();
}
void University::saveRecords(const std::string &filename) {
    std::unique_ptr<Save> save(new Save(this, filename));

    save->execute();
}
void University::addStudent(Student *student) { students_.push_back(student); }

void University::removeStudents(const size_t& index) {
    std::unique_ptr<Remove> remove(new Remove(this, [index](Person *p){
        return p->getIndex() == index;
    }));
    remove->execute();
}

void University::sortByPesel() {
    std::unique_ptr<Sort> sort(new Sort(this, [](Person *l, Person *p) {
        return l->getPesel() < p->getPesel();
    }));

    sort->execute();
}
void University::searchByPesel(int64_t pesel) {

    std::unique_ptr<Search> search(new Search(
            this, [pesel](Person *p) {
                return p->getPesel() == pesel;
            }));
    search->execute();
    auto personVec = search->getresVec();
    std::unique_ptr<University> tempUni(new University(personVec));
    tempUni->printAllDatabase();
}

void University::clearStudents() {
    for (auto *student : students_) {
        delete student;
    }
    students_.clear();
}
void University::searchBySurname(std::string surname) {
    std::unique_ptr<Search> search(new Search(
            this, [surname](Person *p) {
                return p->getSurname().compare(surname) == 0;
            }));
    search->execute();
  
    auto personVec = search->getresVec();
  
    std::unique_ptr<University> tempUni(new University(personVec));
    tempUni->printAllDatabase();

}

void University::sortBySurname() {
  std::unique_ptr<Sort> sort(new Sort(this, [](Person *l, Person *p) {
    return l->getSurname().compare(p->getSurname()) < 0;
  }));

  sort->execute();
}


