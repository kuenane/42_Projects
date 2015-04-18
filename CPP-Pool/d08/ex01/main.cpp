// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 20:03:41 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/13 20:03:42 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

int main (void)
{
	std::cout << "--------------------------------------------" << std::endl;
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	Span toto(5);

	std::cout << "Span created (size 5)" << std::endl << std::endl;

	std::cout << "Span {void}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << toto.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << toto.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl << std::endl;}

	std::cout << "Try to add -2147483648:" << std::endl;
	try{toto.addNumber(-2147483648);} catch (std::exception &e){std::cout << "Failed to add -2147483648";}
	std::cout << "Number succefully added" << std::endl << std::endl;

	std::cout << "Span {-2147483648}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << toto.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << toto.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl << std::endl;}

	std::cout << "Try to add 2147483647:" << std::endl;
	try{toto.addNumber(2147483647);} catch (std::exception &e){std::cout << "Failed to add 2147483647";}
	std::cout << "Number succefully added" << std::endl << std::endl;

	std::cout << "Span {-2147483648 ; 2147483647}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << toto.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << toto.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl;}

	std::cout << std::endl << std::endl << "Try to add 7-10-42:" << std::endl;
	try{toto.addNumber(7);} catch (std::exception &e){std::cout << "Failed to add 7";}
	try{toto.addNumber(10);} catch (std::exception &e){std::cout << "Failed to add 10";}
	try{toto.addNumber(42);} catch (std::exception &e){std::cout << "Failed to add 42";}
	std::cout << "Numbers succefully added" << std::endl << std::endl;

	std::cout << "Span {-2147483648 ; 2147483647 ; 7 ; 10 ; 42}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << toto.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << toto.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl;}

	std::cout << std::endl << std::endl << "Try to add 4242:" << std::endl;
	try{toto.addNumber(4242);} catch (std::exception &e){std::cout << "Failed to add 4242" << std::endl << std::endl;}

	std::cout << "--------------------------------------------" << std::endl;

	Span titi(20000);
	std::cout << std::endl << "Span created (size 20 000)" << std::endl;

	std::vector<int>	vec20k;
	std::srand(std::time(NULL));
	vec20k.resize(19999);
	std::generate_n(vec20k.begin(), 19999, &std::rand);
	std::cout << std::endl << "Vector created (size 19 999 with rand numbers)" << std::endl << std::endl;

	std::cout << "Span {void}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << titi.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << titi.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl << std::endl;}

	std::cout << "Try to add by iterators:" << std::endl;
	try{titi.addNumber(vec20k.begin(), vec20k.end());} catch (std::exception &e){std::cout << "Failed to add by iterators" << std::endl;}
	std::cout << "Number succefully added" << std::endl << std::endl;

	std::cout << "Span {19 999 rand numbers}:" << std::endl;
	std::cout << "Shortest Span = ";
	try{std::cout << titi.shortestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span";}
	std::cout << std::endl << "Longest Span = ";
	try{std::cout << titi.longestSpan();}catch (std::exception &e){std::cout << "Not enough numbers in span" << std::endl;}

	std::cout << std::endl << std::endl << "Try to add 56132:" << std::endl;
	try{titi.addNumber(2147483647);} catch (std::exception &e){std::cout << "Failed to add 56132";}
	std::cout << "Number succefully added" << std::endl << std::endl;

	std::cout << "Try to add 15885:" << std::endl;
	try{titi.addNumber(2147483647);} catch (std::exception &e){std::cout << "Failed to add 15885" << std::endl;}

	return (0);
}
