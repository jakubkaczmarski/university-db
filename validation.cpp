#include "validation.hpp"
#include <cmath>
Validation::Validation(int64_t pesel) : Command(nullptr), pesel_(pesel), correct_(false) {
}

void Validation::execute() {

    const int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 0};
    auto w = static_cast<int>(std::ceil(std::log10(pesel_)));
    if (w == 11) {

        auto value = pesel_;
        auto control = value % 10;
        w-=1;
        value /= 10;

        auto sum = 0;
        while (value > 0) {
            auto c = value % 10;
            sum += c * weights[--w];
            value /= 10;
        }
        auto mod = sum % 10;
        correct_ = ((mod == 0 && control == 0) || (mod != 0 && (10 - mod) == control));
    }
}