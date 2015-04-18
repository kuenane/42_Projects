// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/30 12:05:47 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	bureaucrat_test(void)
{
	Bureaucrat		overload("tutu", 100);
	std::cout << std::endl;

	std::cout << "Try to construct grade 0:" << std::endl;
	try
	{
		Bureaucrat		inf("toto", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try to construct grade 151:" << std::endl;
	try
	{
		Bureaucrat		sup("titi", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try a construct grade 75:" << std::endl;
	try
	{
		Bureaucrat		good("tata", 75);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Overload << :" << std::endl;
	std::cout << overload << std::endl;
	std::cout << std::endl;

	std::cout << "Try to decrement grade 150:" << std::endl;
	try
	{
		overload.decGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try to increment grade 150:" << std::endl;
	try
	{
		overload.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Construct grade 100 and try to increment and decrement it:" << std::endl;
	try
	{
		Bureaucrat		good("good", 100);
		good.incGrade();
		good.decGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
}

void	form_test(void)
{
	Form	f("fofo", 20, 10);
	Bureaucrat		bur2("titu", 50);
	Bureaucrat		bur("tuti", 5);
	std::cout << std::endl;

	std::cout << "Try to construct sign 0, exec 50:" << std::endl;
	try
	{
		Form		inf("toto", 0, 50);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try to construct sign 1, exec 151:" << std::endl;
	try
	{
		Form		sup("titi", 1, 151);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try to construct sign 75, exec 50:" << std::endl;
	try
	{
		Form		good("tata", 75, 50);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Overload << :" << std::endl;
	std::cout << f << std::endl;
	std::cout << "Try to sign a form (20,10) by a bureaucrat (50):" << std::endl;
	bur2.signForm(f);
	std::cout << std::endl;

	std::cout << "Try to sign a form (20,10) by a bureaucrat (5):" << std::endl;
	bur.signForm(f);
	std::cout << std::endl;

	std::cout << "Try to resign it:" << std::endl;
	bur.signForm(f);
	std::cout << std::endl;
}

int		main(void)
{
	bureaucrat_test();
	std::cout << std::endl << "------------------------" << std::endl << std::endl;
	form_test();
	return (0);

}
