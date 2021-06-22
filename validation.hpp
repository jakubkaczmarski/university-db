#pragma once
#include "command.hpp"

class Validation : public Command{
public:
    explicit Validation(int64_t pesel);
    void execute() override;
    bool isCorrect() const { return correct_; }
private:
    int64_t pesel_;
    bool correct_;
};
