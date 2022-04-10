#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
  std::string _target;
  void _execute() const;

public:
  static const std::string FORM_NAME;
  static const int REQ_GRADES_SIGN = 145;
  static const int REQ_GRADES_EXEC = 137;
  static const std::string ASCII_TREE;

  /*
   * constructor destructor
   */
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &copy);
  virtual ~ShrubberyCreationForm();

  /*
   * operator
   */
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

  /*
   * getter setter
   */
  std::string const &getTarget() const;
};

#endif
