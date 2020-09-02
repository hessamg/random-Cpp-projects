// You are asked to implement a double-dispatch visitor called  ExpressionPrinter   for printing different mathematical
// expressions. The range of expressions covers addition and multiplication - please put round brackets around addition but not
// around multiplication! Also, please avoid any blank spaces in output.
// Example:
// Input:  AdditionExpression{Literal{2}, Literal{3}}   -- btw, this is pseudocode, you cannot inline those references
// unfortunately
// Output:  (2+3)
// Here is the corresponding unit test:
//   Value v2{2};
//   Value v3{3};
//   AdditionExpression simple{v2,v3};
//   ExpressionPrinter ep;
//   ep.accept(simple);
//   ASSERT_EQ("(2+3)", ep.str());

#include <string>
#include <sstream>
using namespace std;

struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
  virtual void accept(Value &value) = 0;
  virtual void accept(AdditionExpression &ae) = 0;
  virtual void accept(MultiplicationExpression &me) = 0;
};

struct Expression
{
  virtual void visit(ExpressionVisitor &ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}

  void visit(ExpressionVisitor &ev) override
  {
    ev.accept(*this);
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor &ev) override
  {
    ev.accept(*this);
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
      : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor &ev) override
  {
    ev.accept(*this);
  }
};

struct ExpressionPrinter : ExpressionVisitor
{
  void accept(Value &value) override
  {
    oss << value.value;
  }

  virtual void accept(AdditionExpression &ae) override
  {
    oss << "(";
    ae.lhs.visit(*this);
    oss << "+";
    ae.rhs.visit(*this);
    oss << ")";
  }

  virtual void accept(MultiplicationExpression &me) override
  {
    me.lhs.visit(*this);
    oss << "*";
    me.rhs.visit(*this);
  }

  string str() const
  {
    return oss.str();
  }

private:
  ostringstream oss;
};

#include "gtest/gtest.h"

namespace
{

  class Evaluate : public ::testing::Test
  {
  };

  TEST_F(Evaluate, SimpleAddition)
  {
    Value v{2};
    AdditionExpression simple{v, v};
    ExpressionPrinter ep;
    ep.accept(simple);
    ASSERT_EQ("(2+2)", ep.str());
  }

  TEST_F(Evaluate, ProductOfAdditionAndValue)
  {
    Value _2{2};
    Value _3{3};
    Value _4{4};
    AdditionExpression ae{_2, _3};
    MultiplicationExpression expr{ae, _4};
    ExpressionPrinter ep;
    ep.accept(expr);
    ASSERT_EQ("(2+3)*4", ep.str());
  }

} // namespace

int main(int ac, char *av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}