#include "search.hpp"
#include <algorithm>
#include <functional>
Search::Search(University *university, const std::function<bool(Person *)> &fn)
    : Command(university) {
    fn_ = fn;
}
void Search::execute() {


    for (auto &person : *university_)
        if (fn_(person)) {
            resVec_.push_back(person);
        };
}
