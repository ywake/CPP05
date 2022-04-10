#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
private:
  std::string _target;
  void _execute() const;

public:
  static const std::string FORM_NAME;
  static const int REQ_GRADES_SIGN = 72;
  static const int REQ_GRADES_EXEC = 45;

  /*
   * Constructor/Destructor
   */
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(RobotomyRequestForm const &copy);
  virtual ~RobotomyRequestForm();

  /*
   * Operators
   */
  RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

  /*
   * Getter/Setter
   */
  std::string const &getTarget() const;

  /*
   * Methods
   */
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
