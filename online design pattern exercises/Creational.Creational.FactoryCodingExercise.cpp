// You are given a class called  Person  . The person has two fields:  id  , and  name  .
// Please implement a non-static PersonFactory  that has a  create_person()   method that takes a person's name.
// The  id   of the person should be set as a 0-based index of the object created. So, the first person the factory makes should have id=0, second
// id=1 and so on.

#include <vector>
#include <string>

#include <gtest/gtest.h>

using namespace std;

namespace FactoryExercise
{

  struct Person
  {
    int id;
    string name;
  };

  class PersonFactory
  {
    int id{0};

  public:
    Person create_person(const string &name)
    {
      return {id++, name};
    }
  };

  namespace
  {
    class Evaluate : public testing::Test
    {
    };

    TEST_F(Evaluate, SimplePersonTest)
    {
      PersonFactory pf;

      auto p1 = pf.create_person("Chris");
      ASSERT_EQ("Chris", p1.name);

      auto p2 = pf.create_person("Sarah");
      ASSERT_EQ(1, p2.id) << "Expected the second created person's id to be = 1";
    }
  } // namespace

} // namespace FactoryExercise

int main(int ac, char *av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}