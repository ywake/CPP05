#include "PresidentialPardonForm.hpp"

#include <iostream>

const std::string PresidentialPardonForm::FORM_NAME = "presidential pardon";

/*
 * Constructor/Destructor
 */
PresidentialPardonForm::PresidentialPardonForm() :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &copy) :
    Form(copy),
    _target(copy.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
 * Operators
 */
PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
  if (this != &other) {
    Form::operator=(other);
    _target = other.getTarget();
  }
  return *this;
}

/*
 * Getter/Setter
 */
std::string const &PresidentialPardonForm::getTarget() const { return _target; }

/*
 * Methods
 */
void PresidentialPardonForm::_execute() const
{
  std::cout << _target + " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
