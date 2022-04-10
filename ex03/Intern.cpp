#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

/*
 * Constructor/Destructor
 */
Intern::Intern() {}

Intern::Intern(Intern const &copy) { *this = copy; }

Intern::~Intern() {}

/*
 * Operators
 */
Intern &Intern::operator=(Intern const &other)
{
  if (this != &other) {
  }
  return *this;
}

/*
 * Getter/Setter
 */

/*
 * Methods
 */
Form *Intern::makeForm(std::string const &formName, std::string const &target)
{
  std::string keys[] = {
      ShrubberyCreationForm::FORM_NAME,
      RobotomyRequestForm::FORM_NAME,
      PresidentialPardonForm::FORM_NAME,
  };
  Form *(Intern::*funcs[])(std::string const &target) = {
      &Intern::_makeShrubberyCreationForm,
      &Intern::_makeRobotomyRequestForm,
      &Intern::_makePresidentialPardonForm,
  };

  std::cout << "Intern creates " + formName << std::endl;
  for (size_t i = 0; i < 3; i++) {
    if (formName == keys[i]) {
      return (this->*funcs[i])(target);
    }
  }
  throw std::runtime_error(formName + " is NotFound.");
  return NULL;
}

Form *Intern::_makeShrubberyCreationForm(std::string const &target)
{
  return new ShrubberyCreationForm(target);
}
Form *Intern::_makeRobotomyRequestForm(std::string const &target)
{
  return new RobotomyRequestForm(target);
}
Form *Intern::_makePresidentialPardonForm(std::string const &target)
{
  return new PresidentialPardonForm(target);
}
