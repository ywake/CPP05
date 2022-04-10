#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
private:
  Form *_makeShrubberyCreationForm(std::string const &target);
  Form *_makeRobotomyRequestForm(std::string const &target);
  Form *_makePresidentialPardonForm(std::string const &target);

public:
  /*
   * Constructor/Destructor
   */
  Intern();
  Intern(Intern const &copy);
  ~Intern();

  /*
   * Operators
   */
  Intern &operator=(Intern const &other);

  /*
   * Getter/Setter
   */

  /*
   * Methods
   */
  Form *makeForm(std::string const &formName, std::string const &target);
};

#endif /* INTERN_HPP */
