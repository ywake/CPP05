#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iomanip>
#include <iostream>

#define WIDTH (20)

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

void sign(Form &form, Bureaucrat const &signner)
{
  std::cout << std::setw(WIDTH) << "[Sign by " + signner.getName() + "]";
  try {
    form.beSigned(signner);
    std::cout << "done." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void exec(Form const &form, Bureaucrat const &executor)
{
  std::cout << std::setw(WIDTH) << "[Exec by " + executor.getName() + "]";
  try {
    form.execute(executor);
    std::cout << "done." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void testForm(Form &form)
{
  Bureaucrat high("Mrs.High", 100);
  log("Spawn", high);
  Bureaucrat low("Mr.Low", 150);
  log("Spawn", low);

  log("Create", form);
  // Check sign
  sign(form, low);
  sign(form, high);
  // Check execute
  exec(form, low);
  exec(form, high);
}

int main(void)
{
  std::cout << "\n--- Shrubbery ---" << std::endl;
  ShrubberyCreationForm shrubbery("tree");
  testForm(shrubbery);
  // Check shruberry copy, assign
  {
    ShrubberyCreationForm copy(shrubbery);
    log("Copy", copy);
    ShrubberyCreationForm assign;
    assign = copy;
    log("Assign", assign);
  }
}
