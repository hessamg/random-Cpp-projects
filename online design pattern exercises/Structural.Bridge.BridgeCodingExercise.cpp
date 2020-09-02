// You are given an example of an inheritance hierarchy which results in Cartesian-product duplication.
// Please refactor this hierarchy, giving the base class  Shape   an initializer that takes a  Renderer   defined as
//  struct Renderer
//  {
//  virtual string what_to_render_as() const = 0;
//  }
// as well as VectorRenderer and RasterRenderer.
// The expectation is that each constructed object has a member called  str()   that returns its textual representation, for example,
// Triangle(RasterRenderer()).str() // returns "Drawing Triangle as pixels"

#include <string>
#include <sstream>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct Shape
{
    string name;
    const Renderer& renderer;
    
    Shape(const Renderer& renderer): renderer{renderer} {} 
    
    string str() const
    {
        ostringstream oss;
        oss << "Drawing " + name + " as " << renderer.what_to_render_as();
        return oss.str();
    }
};

struct Triangle : Shape
{
    Triangle(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Triangle";
  }
};

struct Square : Shape
{
    Square(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Square";
  }
};

struct VectorRenderer : Renderer
{ 
    virtual string what_to_render_as() const override
    {
        return "lines";
    }
};

struct RasterRenderer : Renderer
{
    virtual string what_to_render_as() const override
    {
        return "pixels";
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
    ASSERT_EQ("Drawing Square as lines",
      Square{VectorRenderer{}}.str())
  }

} // namespace