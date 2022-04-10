#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iomanip>
#include <iostream>

void test(std::string const &formName, std::string const &target)
{
  Intern intern;
  Form *form;
  Bureaucrat king("King", 1);

  try {
    form = intern.makeForm(formName, target);
    king.executeForm(*form);
    delete form;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

int main(void)
{
  std::cout << "--- Shrubbery ---" << std::endl;
  test(ShrubberyCreationForm::FORM_NAME, "tree");
  std::cout << "--- Robotomy ---" << std::endl;
  test(RobotomyRequestForm::FORM_NAME, "pawapuro-kun");
  std::cout << "--- President ---" << std::endl;
  test(PresidentialPardonForm::FORM_NAME, "Snowden");
  std::cout << "--- NotFound ---" << std::endl;
  test("aaaa", "bbbb");

  Intern intern;
  {
    Intern copy(intern);
    Intern assign;
    assign = intern;
  }
}
