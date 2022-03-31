#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"

class Bureaucrat
{
private:
  const std::string _name;
  int _grade;
  void _checkGrade(int grade) const;
  void _setGrade(int newGrade);

public:
  static const int HIGHEST_GRADE = 1;
  static const int LOWEST_GRADE = 150;

  /*
   * constructor destructor
   */
  Bureaucrat();
  Bureaucrat(std::string const &name, int const grade);
  Bureaucrat(Bureaucrat const &copy);
  ~Bureaucrat();

  /*
   * operator
   */
  Bureaucrat &operator=(Bureaucrat const &other);

  /*
   * getter setter
   */
  const std::string &getName() const;
  int getGrade() const;

  /*
   * methods
   */
  int gradeUp();
  int gradeDown();
  void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
