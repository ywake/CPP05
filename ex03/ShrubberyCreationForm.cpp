#include "ShrubberyCreationForm.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>

const std::string ShrubberyCreationForm::FORM_NAME = "Shruberry Creation";
const std::string ShrubberyCreationForm::ASCII_TREE = "    _\\/_\n"
                                                      "     /\\\n"
                                                      "     /\\\n"
                                                      "    /  \\\n"
                                                      "    /~~\\o\n"
                                                      "   /o   \\\n"
                                                      "  /~~*~~~\\\n"
                                                      " o/    o \\\n"
                                                      " /~~~~~~~~\\~`\n"
                                                      "/__*_______\\\n"
                                                      "     ||\n"
                                                      "   \\====/\n"
                                                      "    \\__/\n";

/*
 * constructor destructor
 */
ShrubberyCreationForm::ShrubberyCreationForm() :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
    Form(FORM_NAME, REQ_GRADES_SIGN, REQ_GRADES_EXEC), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
    ShrubberyCreationForm const &copy) :
    Form(copy),
    _target(copy.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
 * operator
 */
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
  if (this != &other) {
    Form::operator=(other);
    _target = other.getTarget();
  }
  return *this;
}

/*
 * getter setter
 */
std::string const &ShrubberyCreationForm::getTarget() const { return _target; }

/*
 * methods
 */
void ShrubberyCreationForm::_execute() const
{
  std::ofstream ofs(_target + "_shrubbery");
  if (!ofs) {
    // std::perror("Shrubbery Creation Form");
    throw std::invalid_argument(std::strerror(errno));
  }
  ofs << ASCII_TREE << std::endl;
}
