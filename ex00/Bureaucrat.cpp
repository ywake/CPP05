#include "Bureaucrat.hpp"

/*
 * constructor destructor
 */
Bureaucrat::Bureaucrat() : _name("NoName"), _grade(LOWEST_GRADE) {}
Bureaucrat::Bureaucrat(std::string const &name, int const grade) :
    _name(name), _grade(grade)
{
  _checkGrade(_grade);
}
Bureaucrat::Bureaucrat(Bureaucrat const &copy) :
    _name(copy.getName()), _grade(copy.getGrade())
{
  _checkGrade(_grade);
}
Bureaucrat::~Bureaucrat() {}

/*
 * operator
 */
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
  if (this != &other) {
    this->_grade = other.getGrade();
  }
  return *this;
}

/*
 * getter setter
 */
const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }
void Bureaucrat::_setGrade(int newGrade)
{
  _checkGrade(newGrade);
  _grade = newGrade;
}

/*
 * methods
 */
int Bureaucrat::gradeUp()
{
  _setGrade(_grade - 1);
  return _grade;
}
int Bureaucrat::gradeDown()
{
  _setGrade(_grade + 1);
  return _grade;
}
void Bureaucrat::_checkGrade(int grade) const
{
  if (grade < HIGHEST_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > LOWEST_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
}

/*
 * exception
 */
Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string &msg) :
    std::out_of_range(msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) :
    std::out_of_range(msg)
{
}

/*
 * overload
 */
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
