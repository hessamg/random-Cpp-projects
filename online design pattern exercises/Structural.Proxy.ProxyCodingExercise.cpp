// You are given the  Person   class and asked to write a  ResponsiblePerson   wrapper/proxy that does the following:
// Allows person to drink unless they are younger than 18 (in that case, return "too young")
// Allows person to drive unless they are younger than 16 (otherwise, "too young")
// In case of driving while drink, returns "dead"
// The interface of  ResponsiblePerson   has to match that of  Person  , except for the constructor, which takes an underlying Person
// object..

#include <string>
using namespace std;

class Person
{
  friend class ResponsiblePerson;
  int age;

public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
  ResponsiblePerson(const Person &person) : person(person) {}

  int get_age() const { return person.age; }
  void set_age(int value) { person.age = value; }

  string drink() const
  {
    if (get_age() < 18)
    {
      return "too young";
    }
    return person.drink();
  }

  string drive() const
  {
    if (get_age() < 16)
    {
      return "too young";
    }
    return person.drive();
  }
  string drink_and_drive() const { return "dead"; }

private:
  Person person;
};

#include "gtest/gtest.h"

namespace
{
  class Evaluate : public testing::Test
  {
  public:
  };

  TEST_F(Evaluate, BaselineTest)
  {
    Person p{10};
    ResponsiblePerson rp{p};

    ASSERT_EQ("too young", rp.drive());
    ASSERT_EQ("too young", rp.drink());
    ASSERT_EQ("dead", rp.drink_and_drive());

    rp.set_age(20);

    ASSERT_EQ("driving", rp.drive());
    ASSERT_EQ("drinking", rp.drink());
    ASSERT_EQ("dead", rp.drink_and_drive());
  }

} // namespace

int main(int ac, char *av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}