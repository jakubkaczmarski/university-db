#include "gtest/gtest.h"
#include "person.hpp"
#include <memory>
#include <string>
class TestPerson : public Person{
public:
    explicit TestPerson() : Person() {

    }

    explicit TestPerson(const std::string& name,
                        const std::string& surname,
                        const std::string& address
                        ) : Person(name, surname, address) {

    }
    explicit TestPerson(const std::string& name,
                        const std::string& surname,
                        const std::string& address,
                        int64_t pesel,
                        Gender sex
    ) : Person(name, surname, address, pesel, sex) {

    }



    void print() override {

    }
};

TEST(PersonTest, Should_be_empty_fields_when_the_default_constructor_is_created) {
    auto person = std::unique_ptr<TestPerson>(new TestPerson());

    ASSERT_TRUE(person->getName().compare("") == 0);
    ASSERT_TRUE(person->getSurname().compare("") == 0);
    ASSERT_TRUE(person->getAddress().compare("") == 0);
    ASSERT_EQ(person->getPesel(),  0LL);
    ASSERT_EQ(person->getSex(),  Gender::Male);
}

TEST(PersonTest, It_should_be_partially_filled_in_fields_when_we_use_a_constructor_with_parameters) {
    auto person = std::unique_ptr<TestPerson>(new TestPerson("Judie", "Foster", "New York"));

    ASSERT_TRUE(person->getName().compare("Judie") == 0);
    ASSERT_TRUE(person->getSurname().compare("Foster") == 0);
    ASSERT_TRUE(person->getAddress().compare("New York") == 0);
    ASSERT_EQ(person->getPesel(),  0LL);
    ASSERT_EQ(person->getSex(),  Gender::Female);
}

TEST(PersonTest, It_should_populate_all_fields_when_we_use_the_constructor_with_all_parameters) {
    auto person = std::unique_ptr<TestPerson>(new TestPerson("Tom", "Cruise", "Hollywood", 10003230001, Gender::Male));

    ASSERT_TRUE(person->getName().compare("Tom") == 0);
    ASSERT_TRUE(person->getSurname().compare("Cruise") == 0);
    ASSERT_TRUE(person->getAddress().compare("Hollywood") == 0);
    ASSERT_EQ(person->getPesel(),  10003230001LL);
    ASSERT_EQ(person->getSex(),  Gender::Male);
}