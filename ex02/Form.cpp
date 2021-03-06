#include "Form.hpp"

/*
 * constructor destructor
 */
Form::Form() :
    _name("NoName"), _isSigned(false), _requiredGradeToSign(1),
    _requiredGradeToExecute(1)
{
}

Form::Form(std::string const &name, int requiredGradeToSign,
           int requiredGradeToExecute) :
    _name(name),
    _isSigned(false), _requiredGradeToSign(requiredGradeToSign),
    _requiredGradeToExecute(requiredGradeToExecute)
{
}

Form::Form(Form const &copy) :
    _name(copy.getName()), _isSigned(copy.isSigned()),
    _requiredGradeToSign(copy.getRequiredGradeToSign()),
    _requiredGradeToExecute(copy.getRequiredGradeToExecute())
{
}

Form::~Form() {}

/*
 * operator
 */
Form &Form::operator=(Form const &other)
{
  if (this != &other) {
    _isSigned = other.isSigned();
  }
  return *this;
}

/*
 * getter setter
 */
const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getRequiredGradeToSign() const { return _requiredGradeToSign; }
int Form::getRequiredGradeToExecute() const { return _requiredGradeToExecute; }

/*
 * methods
 */
void Form::beSigned(Bureaucrat const &b)
{
  if (b.getGrade() > _requiredGradeToSign) {
    throw Form::GradeTooLowException();
  }
  _isSigned = true;
}

void Form::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() > _requiredGradeToExecute) {
    throw Form::GradeTooLowException();
  }
  _execute();
}

/*
 * exception
 */
Form::GradeTooHighException::GradeTooHighException(const std::string &msg) :
    std::out_of_range(msg)
{
}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg) :
    std::out_of_range(msg)
{
}

/*
 * overload
 */
std::ostream &operator<<(std::ostream &os, Form const &f)
{
  os << f.getName() << " is " << (f.isSigned() ? "" : "not ") << "sined. "
     << "Requires a minimum of " << f.getRequiredGradeToSign()
     << " grades to sign and " << f.getRequiredGradeToExecute()
     << " to execute.";
  return os;
}
