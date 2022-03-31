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

void log(std::string const &title, Form const &f)
{
  std::cout << std::left << std::setw(WIDTH) << "[" + title + "]" << f
            << std::endl;
}

int main(void)
{
  Bureaucrat high("high", 100);
  log("Spawn", high);

  Bureaucrat low("low", 101);
  log("Spawn", low);

  Form a("Form-A", 100, 10);
  log("Create", a);

  {
    Form copy(a);
    log("Copy", copy);
    Form assign;
    assign = a;
    log("Assign a", assign);
  }
  std::cout << std::endl;
  low.signForm(a);
  high.signForm(a);
  std::cout << std::endl;

  log("Signed", a);

  {
    Form copy(a);
    log("Copy", copy);
    Form assign;
    assign = a;
    log("Assign a", assign);
  }
}
