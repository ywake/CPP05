#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

class Form
{
private:
  const std::string _name;
  bool _isSigned = false;
  const int _requiredGradeToSign;
  const int _requiredGradeToExecute;

public:
  /*
   * constructor destructor
   */
  Form();
  Form(std::string const &name, int requiredGradeToSign,
       int requiredGradeToExecute);
  Form(Form const &copy);
  ~Form();

  /*
   * operator
   */
  Form &operator=(Form const &other);

  /*
   * getter setter
   */
  const std::string &getName() const;
  bool isSigned() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;

  /*
   * methods
   */
  void beSigned(Bureaucrat const &bureaucrat);

  /*
   * exception
   */
  class GradeTooHighException : public std::out_of_range
  {
  public:
    GradeTooHighException(const std::string &msg = "The grade is too high.");
  };

  class GradeTooLowException : public std::out_of_range
  {
  public:
    GradeTooLowException(const std::string &msg = "The grade is too low.");
  };
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
