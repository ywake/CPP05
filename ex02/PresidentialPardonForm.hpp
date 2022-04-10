#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
private:
  std::string _target;
  void _execute() const;

public:
  static const std::string FORM_NAME;
  static const int REQ_GRADES_SIGN = 25;
  static const int REQ_GRADES_EXEC = 5;
  /*
   * Constructor/Destructor
   */
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(PresidentialPardonForm const &copy);
  virtual ~PresidentialPardonForm();

  /*
   * Operators
   */
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

  /*
   * Getter/Setter
   */
  std::string const &getTarget() const;

  /*
   * Methods
   */
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
