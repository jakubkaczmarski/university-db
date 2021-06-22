#pragma once
#include "command.hpp"
#include "university.hpp"
#include <vector>
#include <functional>

class Sort : public Command {
public:
    explicit Sort(University* university, const std::function<bool(Person*,Person*)>& fn);
    virtual void execute() override;
private:
  std::function<bool(Person*,Person*)> fn_;
};