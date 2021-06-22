#include "remove.hpp"

Remove::Remove(University* university, const std::function<bool(Person*)>& fn) 
    : Command(university)
    , fn_(fn) {} 

void Remove::execute() {
    auto removeIt = university_->end();
    for (auto it = university_->begin(); it != university_->end(); it++) {
        if (fn_(*it)) {
        //if ((*it)->getIndex() == index) {
            removeIt = it;
            break;
        }
    }
    if (removeIt != university_->end()) {
        university_->erase(removeIt);
        delete *removeIt;
    }
}
