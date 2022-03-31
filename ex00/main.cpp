#include "Bureaucrat.hpp"

#include <iomanip>
#include <iostream>

#define WIDTH (15)

void log(std::string const &title, std::string const &what)
{
  std::cout << std::left << std::setw(WIDTH) << "[" + title + "]" << what
            << std::endl;
}

void log(std::string const &title, Bureaucrat const &b)
{
  std::cout << std::left << std::setw(WIDTH) << "[" + title + "]" << b
            << std::endl;
}

int main(void)
{
  // constructor normal
  Bureaucrat a("aaa", 1);
  log("Normal", a);

  // constructor normal
  Bureaucrat b("bbb", 150);
  log("Normal", b);

  // constructor too high
  try {
    Bureaucrat c("ccc", 0);
    log("TooHigh", c);
  } catch (const std::exception &e) {
    log("TooHigh", e.what());
  }

  // constructor too low
  try {
    Bureaucrat c("ccc", 151);
    log("TooLow", c);
  } catch (const std::exception &e) {
    log("TooLow", e.what());
  }

  // copy constructor
  Bureaucrat copy(a);
  log("Copy a", copy);

  // assignnation
  Bureaucrat assign;
  assign = a;
  log("Assign a", assign);

  // grade up normal
  b.gradeUp();
  log("b.gradeUp", b);

  // grade down normal
  b.gradeDown();
  log("b.gradeDown", b);

  // grade up too high
  try {
    a.gradeUp();
  } catch (const std::exception &e) {
    log("a.gradeUp", e.what());
  }
  log("a", a);

  // grade up too low
  try {
    b.gradeDown();
  } catch (const std::exception &e) {
    log("b.gradeDown", e.what());
  }
  log("b", b);
}
