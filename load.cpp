#include "load.hpp"
#include <fstream>


Load::Load(University *university, const std::string &filename)
    : Command(university) {
    std::ifstream ifs(filename);
    if (ifs.good()) {
        file = json::parse(ifs);
    }
}

void Load::execute() {
    if (!file.empty()) {

        university_->clearStudents();
        for (auto &object : file) {

            university_->addStudent(new Student(
                    object["name"],
                    object["surname"],
                    object["address"],
                    object["index"],
                    object["pesel"],
                    object["sex"]));
        }
    }
}
Load::~Load() {
}
