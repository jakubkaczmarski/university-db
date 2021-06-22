#include "university.hpp"
#include "load.hpp"
#include "save.hpp"
#include "sort.hpp"
#include "student.hpp"
#include <memory>


void University::loadRecords(const std::string& filename) {
    std::unique_ptr<Load> load(new Load(this, filename));

    load->execute();
}
void University::saveRecords(const std::string& filename) {
    std::unique_ptr<Save> save(new Save(this, filename));

    save->execute();
}
void University::addStudent(Student *student) { students_.push_back(student); }
void University::printAllDatabase() {
  for (auto *student : students_)
    student->print();
}
void University::sortByPesel() {
  std::unique_ptr<Sort> sort(new Sort(this, [](Person *l, Person *p) {
    return l->getPesel() < p->getPesel();
  }));

  sort->execute();
}
void University::sortBySurname() {
  std::unique_ptr<Sort> sort(new Sort(this, [](Person *l, Person *p) {
    return l->getSurname().compare(p->getSurname()) < 0;
  }));

  sort->execute();
}
std::vector<Person *> University::getStudents() const {
    return students_;
}
void University::clearStudents() {
    for (auto *student : students_) {
        delete student;
    }
    students_.clear();
}
