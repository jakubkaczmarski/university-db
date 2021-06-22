#pragma once
#include "command.hpp"
#include "university.hpp"
#include <functional>
#include <vector>
class Search : public Command {
public:
    explicit Search(University *university, const std::function<bool(Person *)> &fn);
    virtual void execute() override;
    std::vector<Person *> getresVec() {
        return resVec_;
    };

private:
    std::vector<Person *> resVec_{};
    std::function<bool(Person *)> fn_;
};