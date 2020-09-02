// You are asked to implement the Builder design pattern for rendering simple chunks of code.
// Sample use of the builder you are asked to create:
//     auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
//     cout << cb;
// The expected output of the above code is:
//     class Person
//     {
//        string name;
//        int age;
//     };
// Please observe the same placement of curly braces and use two-space indentation.

#include <string>
#include <ostream>
#include <vector>

using namespace std;

class CodeBuilder;

struct Code
{
  string name;
  string type;
  vector<Code> elements;

  Code() {}
  Code(const string &name, const string &type)
      : name(name),
        type(type)
  {
  }
};

class CodeBuilder
{
  Code code;

public:
  CodeBuilder(const string &class_name)
  {
    code.name = class_name;
  }

  CodeBuilder &add_field(const string &name, const string &type)
  {
    Code c{name, type};
    code.elements.emplace_back(c);
    return *this;
  }

  friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
  {
    os << "class " << obj.code.name << "\n{\n";
    for (auto elem : obj.code.elements)
    {
      os << "  " << elem.type << " " << elem.name << ";" << endl;
    }
    os << "};";
    return os;
  }
};

#include <algorithm>
#include <cctype>
#include <locale>

#include "gtest/gtest.h"

// trim from start (in place)
static inline void ltrim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
          }).base(),
          s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s)
{
  ltrim(s);
  return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s)
{
  rtrim(s);
  return s;
}

namespace
{
  class Evaluate : public testing::Test
  {
  };

  TEST_F(Evaluate, EmptyTest)
  {
    CodeBuilder cb{"Foo"};
    ostringstream oss;
    oss << cb;
    auto printed = oss.str();
    trim(printed);
    ASSERT_EQ("class Foo\n{\n};", printed);
  }

  TEST_F(Evaluate, PersonTest)
  {
    auto cb = CodeBuilder{"Person"}
                  .add_field("name", "string")
                  .add_field("age", "int");
    ostringstream oss;
    oss << cb;
    auto printed = oss.str();
    trim(printed);
    ASSERT_EQ("class Person\n{\n  string name;\n  int age;\n};", printed);
  }
} // namespace