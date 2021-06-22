#pragma once
#include "command.hpp"
#include "university.hpp"
#include <functional>
#include <vector>
class DeleteC : public Command {
public:
    explicit DeleteC(University *university, const std::function<bool(Student *)> &fn);
    virtual void execute() override;
    std::vector<Student *> getresVec() {
        return resVec_;
    };

private:
    std::vector<Student *> resVec_{};
    std::function<bool(Student *)> fn_;
};