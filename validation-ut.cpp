#include "gtest/gtest.h"
#include "validation.hpp"
#include <memory>


class TestValidation : public Validation {
public:
    explicit TestValidation(int64_t pesel) : Validation(pesel) {

    }
    void execute() override {
        Validation::execute();
    }


};

TEST(ValidationTest, It_should_give_the_correct_result_with_the_correct_pesel) {
    auto validation = std::unique_ptr<TestValidation>(new TestValidation(48092786138));


    validation->execute();
    ASSERT_TRUE(validation->isCorrect());
}

TEST(ValidationTest, It_should_give_the_incorrect_result_with_the_incorrect_pesel) {
    auto validation = std::unique_ptr<TestValidation>(new TestValidation(48092786112));


    validation->execute();
    ASSERT_FALSE(validation->isCorrect());
}

TEST(ValidationTest, It_should_give_the_positive_result_with_the_correct_pesel_starting_with_zero) {
    auto validation = std::unique_ptr<TestValidation>(new TestValidation(stoll(std::string{"04320827114"})));


    validation->execute();
    ASSERT_TRUE(validation->isCorrect());
}

TEST(ValidationTest, It_should_give_the_negative_result_when_there_is_insufficient_number_of_digits) {
    auto validation = std::unique_ptr<TestValidation>(new TestValidation(stoll(std::string{"114"})));


    validation->execute();
    ASSERT_FALSE(validation->isCorrect());
}