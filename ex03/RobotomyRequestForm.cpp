#include "RobotomyRequestForm.hpp"

#include <ctime>
#include <iostream>

const std::string RobotomyRequestForm::FORM_NAME = "Robotomy Request";

/*
 * Constructor/Destructor
 */
RobotomyRequestForm::RobotomyRequestForm() :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :
    Form(copy), _target(copy.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
 * Operators
 */
RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
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
std::string const &RobotomyRequestForm::getTarget() const { return _target; }

/*
 * Methods
 */
void RobotomyRequestForm::_execute() const
{
  std::cout << "WHEEEEEEE..." << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2) {
    std::cout << "Success! " + _target + " has been robotomized." << std::endl;
  } else {
    std::cout << "Failed... Scientific progress comes at a cost!" << std::endl;
  }
}
