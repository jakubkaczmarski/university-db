#include "gtest/gtest.h"
#include "command.hpp"
#include <memory>
class TestCommand : public Command{
public:
    explicit TestCommand() : Command(nullptr) {

    }
    explicit TestCommand(University* university) : Command(university) {

    }
    University* getUniversity() {
        return university_;
    }
    void execute() override {
        counter++;
    }
    int counter = 0;
};

TEST(CommandTest, Should_receive_an_empty_pointer_when_no_object_is_specified) {
    auto command = std::unique_ptr<TestCommand>(new TestCommand());

    auto* university = command->getUniversity();
    EXPECT_TRUE(university == nullptr);
}

TEST(CommandTest, Should_should_receive_a_pointer_when_given_an_object) {
    auto university = std::unique_ptr<University>(new University());
    auto command = std::unique_ptr<TestCommand>(new TestCommand(university.get()));

    EXPECT_TRUE(university.get() == command->getUniversity());
}

TEST(CommandTest, Should_call_the_execute_method_to_increment_the_counter) {
    auto command = std::unique_ptr<TestCommand>(new TestCommand());

    EXPECT_EQ(command->counter, 0);

    command->execute();
    EXPECT_EQ(command->counter, 1);
}
