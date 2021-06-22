#include "gtest/gtest.h"
#include "remove.hpp"
#include <memory>

class TestRemove : public Remove{
public:
    explicit TestRemove(const std::function<bool(Person*)>& fn) : Remove(nullptr, fn), fn(fn) {

    }
    void execute() override {
        if (fn(nullptr)) {
            counter = 1;
        }
    }
    int counter = 0;
private:
    const std::function<bool(Person*)>& fn;
};

TEST(RemoveTest, Should_not_remove_the_object_when_the_condition_is_not_met) {
    auto remove = std::unique_ptr<TestRemove>(new TestRemove([](Person* p){
        return false;
    }));
    remove->execute();
    ASSERT_EQ(remove->counter, 0);
}

TEST(RemoveTest, Should_remove_the_object_when_the_condition_is_met) {
    auto remove = std::unique_ptr<TestRemove>(new TestRemove([](Person* p){
      return true;
    }));
    remove->execute();
    ASSERT_EQ(remove->counter, 1);
}