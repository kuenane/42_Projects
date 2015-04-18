// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/28 16:04:24 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat		overload("tutu", 150);
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
	
	return (0);
	
}
