// You are given a class called  Sentence  , which takes a string such as "hello world". You need to provide an interface such that the
// indexer ( operator []  ) returns a  WordToken   that can be used to capitalize a particular word in the sentence.
// Typical use would be something like:
//   Sentence sentence("hello world");
//   sentence[1].capitalize = true;
//   cout << sentence.str(); // prints "hello WORLD"

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };

  vector<string> words;
  map<int, WordToken> tokens;

  Sentence(const string &text)
  {
    istringstream iss{text};
    words = vector<string>(istream_iterator<string>{iss},
                           istream_iterator<string>{});
  }

  WordToken &operator[](size_t index)
  {
    tokens[index] = WordToken{};
    return tokens[index];
  }

  string str() const
  {
    vector<string> ws;
    for (size_t i = 0; i < words.size(); ++i)
    {
      string w = words[i];
      auto t = tokens.find(i);
      if (t != tokens.end() && t->second.capitalize)
      {
        transform(w.begin(), w.end(), w.begin(), (int (&)(int))toupper);
      }
      ws.push_back(w);
    }

    ostringstream oss;
    for (size_t i = 0; i < ws.size(); ++i)
    {
      oss << ws[i];
      if (i + 1 != ws.size())
        oss << " ";
    }
    return oss.str();
  }
};

#include "gtest/gtest.h"

//#include "helpers/iohelper.h"

//#include "exercise.cpp"

namespace
{
  class Evaluate : public testing::Test
  {
  public:
  };

  TEST_F(Evaluate, BaselineTest)
  {
    Sentence s{"alpha beta gamma"};
    s[0].capitalize = s[2].capitalize = false;
    s[1].capitalize = true;
    ASSERT_EQ("alpha BETA gamma", s.str());
  }

} // namespace

int main(int ac, char *av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}