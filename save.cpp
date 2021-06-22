#include "save.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Save::Save(University *university, const std::string& filename)
    : Command(university) {
    ofs.open(filename);
}

void Save::execute() {
    json array = json::array();
    for (auto it = university_->begin(); it != university_->end(); it++) {
            json object = json::object();
            object["name"] = (*it)->getName();
            object["surname"] = (*it)->getSurname();
            object["address"] = (*it)->getAddress();
            object["index"] = (*it)->getIndex();
            object["pesel"] = (*it)->getPesel();
            object["sex"] = (*it)->getSex();
            array.push_back(object);
    }
    ofs << array;
}
Save::~Save() {
    ofs.close();
}

