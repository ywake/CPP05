#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iomanip>
#include <iostream>

#define WIDTH (20)
#define THIN "\e[2m"
#define END "\e[0m"

template <class T>

void log(std::string const &title, T const &obj)
{
  std::cout << std::left << THIN << std::setw(WIDTH) << "[" + title + "]" << obj
            << END << std::endl;
}

void sign(Form &form, Bureaucrat const &signner)
{
  std::cout << THIN << std::setw(WIDTH) << "[Sign by " + signner.getName() + "]"
            << END;
  try {
    form.beSigned(signner);
    std::cout << THIN "done." END << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void exec(Form const &form, Bureaucrat const &executor)
{
  std::cout << THIN << std::setw(WIDTH)
            << "[Exec by " + executor.getName() + "]" << END;
  executor.executeForm(form);
}

void testForm(Form &form, int highGrade, int lowGrade)
{
  Bureaucrat high("Mrs.High", highGrade);
  log("Spawn", high);
  Bureaucrat low("Mr.Low", lowGrade);
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
  testForm(shrubbery, 100, 150);
  // Check shruberry copy, assign
  {
    ShrubberyCreationForm copy(shrubbery);
    log("Copy", copy);
    ShrubberyCreationForm assign;
    assign = copy;
    log("Assign", assign);
    std::cout << THIN "target: " << shrubbery.getTarget() + ", "
              << copy.getTarget() + ", " << assign.getTarget() << END
              << std::endl;
  }

  std::cout << "\n--- Robotomy ---" << std::endl;
  RobotomyRequestForm robotomy("pawapuro-kun");
  testForm(robotomy, 45, 150);
  {
    RobotomyRequestForm copy(robotomy);
    log("Copy", copy);
    RobotomyRequestForm assign;
    assign = copy;
    log("Assign", assign);
    std::cout << THIN "target: " << robotomy.getTarget() + ", "
              << copy.getTarget() + ", " << assign.getTarget() << END
              << std::endl;
  }

  std::cout << "\n--- Presidential ---" << std::endl;
  PresidentialPardonForm presidential("Snowden");
  testForm(presidential, 1, 150);
  {
    PresidentialPardonForm copy(presidential);
    log("Copy", copy);
    PresidentialPardonForm assign;
    assign = copy;
    log("Assign", assign);
    std::cout << THIN "target: " << presidential.getTarget() + ", "
              << copy.getTarget() + ", " << assign.getTarget() << END
              << std::endl;
  }
}
