#pragma once
#include "command.hpp"

class Print : public Command {
public:
    Print(University *university);
    virtual void execute() override;
};
