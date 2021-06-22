#include "delete.hpp"
#include <algorithm>
#include <functional>
DeleteC::DeleteC(University *university, const std::function<bool(Student *)> &fn)
    : Command(university) {
    fn_ = fn;
}
void DeleteC::execute() {


    for (auto &person : resVec_)
        {
            std::cout << person->getName() << std::endl;
        }
}
