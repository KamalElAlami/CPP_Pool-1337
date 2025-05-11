#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		void execute(Bureaucrat const& executor) const;
		const std::string& getTarget(void) const;
		class FileOpenException : public std::exception
		{
			const char* what() const throw();
		};
		class TargetDoesntMeetRequirements : public std::exception
		{
			const char* what() const throw();
		};
	
};

#endif