#pragma once
#include "command.hpp"
#include "university.hpp"
#include <vector>
#include <functional>

class Remove : public Command {
public:
    explicit Remove(University* university, const std::function<bool(Person*)>& fn);
    virtual void execute() override;
private:
  std::function<bool(Person*)> fn_;
};