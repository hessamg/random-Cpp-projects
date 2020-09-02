// Implementing a singleton is a bit too easy, so you've got a different challenge. 
// You are given the function SingletonTester::is_singleton()   defined below. This function takes a factory, and needs to return
// true   or false   depending on whether that factory produces singletons.
// This one's actually easy. Ask yourself: what traits do two 'instances' of a singleton have in common?

#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    T* _1 = factory();
    T* _2 = factory();
    return _1 == _2;
  }
};

#include "gtest/gtest.h"

namespace
{
  class Evaluate : public testing::Test
  {
  };

  TEST_F(Evaluate, SimpleTest)
  {
    SingletonTester tester;
    ASSERT_TRUE(tester.is_singleton<SingletonTester>(
      [&]() -> SingletonTester* { return &tester; }))
      << "Expected a singleton in this case; provided lambda is yielding the same object over and over.";
    ASSERT_FALSE(tester.is_singleton<SingletonTester>([]() { return new SingletonTester{}; }));
  }
} // namespace
