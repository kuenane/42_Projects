// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 11:54:00 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/14 11:54:08 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "mutantstack.hpp"
#include <list>

int main()
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "******** TEST WITH MUTANTSTACK *******" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	MutantStack<int> mstack;
	std::cout << "Created a void mstack" << std::endl << std::endl;

	std::cout << "MSTACK {void}" << std::endl;
	std::cout << "Is is empty? ";
	if (mstack.empty())
		std::cout << "Yes" << std::endl << std::endl;
	else
		std::cout << "No" << std::endl;

	std::cout << "MSTACK {void}" << std::endl;
	std::cout << "Push 5 and 17: ";
	mstack.push(5);
	mstack.push(17);
	if (mstack.size() == 2)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "MSTACK {5 17}" << std::endl;
	std::cout << "Top elem is " << mstack.top() << std::endl << std::endl;

	std::cout << "MSTACK {5 17}" << std::endl;
	std::cout << "mstack contain " << mstack.size() << " element(s)." << std::endl << std::endl;

	std::cout << "MSTACK {5 17}" << std::endl;
	mstack.pop();
	std::cout << "Pop one time: ";
	if (mstack.size() == 1)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "MSTACK {5}" << std::endl;
	std::cout << "mstack contain " << mstack.size() << " element(s)." << std::endl << std::endl;

	std::cout << "MSTACK {5}" << std::endl;
	std::cout << "Push 1 5 87 42 : ";
	mstack.push(1);
	mstack.push(5);
	mstack.push(87);
	mstack.push(42);
	if (mstack.size() == 5)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "MSTACK {5 1 5 87 42}" << std::endl;
	std::cout << "mstack contain " << mstack.size() << " element(s)." << std::endl << std::endl;

	std::cout << "Create iterators begin/end" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << std::endl << "it++ then it-- to see if is OK" << std::endl << std::endl;
	++it;
	--it;
	ite--;
	ite++;

	std::cout << "use both in while to print the mstack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl << "--------------------------------------" << std::endl;
	std::cout << "********* TEST WITH STD::LIST ********" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	std::list<int> lst;
	std::cout << "Created a void lst" << std::endl << std::endl;

	std::cout << "lst {void}" << std::endl;
	std::cout << "Is is empty? ";
	if (lst.empty())
		std::cout << "Yes" << std::endl << std::endl;
	else
		std::cout << "No" << std::endl;

	std::cout << "lst {void}" << std::endl;
	std::cout << "Push 5 and 17: ";
	lst.push_back(5);
	lst.push_back(17);
	if (lst.size() == 2)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "lst {5 17}" << std::endl;
	std::cout << "Top elem is " << lst.back() << std::endl << std::endl;

	std::cout << "lst {5 17}" << std::endl;
	std::cout << "lst contain " << lst.size() << " element(s)." << std::endl << std::endl;

	std::cout << "lst {5 17}" << std::endl;
	lst.pop_back();
	std::cout << "Pop one time: ";
	if (lst.size() == 1)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "lst {5}" << std::endl;
	std::cout << "lst contain " << lst.size() << " element(s)." << std::endl << std::endl;

	std::cout << "lst {5}" << std::endl;
	std::cout << "Push_back 1 5 87 42 : ";
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(87);
	lst.push_back(42);
	if (lst.size() == 5)
		std::cout << "OK" << std::endl << std::endl;
	else
		std::cout << "KO" << std::endl;

	std::cout << "lst {5 1 5 87 42}" << std::endl;
	std::cout << "lst contain " << lst.size() << " element(s)." << std::endl << std::endl;

	std::cout << "Create iterators begin/end" << std::endl;
	std::list<int>::iterator itlst = lst.begin();
	std::list<int>::iterator itelst = lst.end();

	std::cout << std::endl << "it++ then it-- to see if is OK" << std::endl << std::endl;
	++itlst;
	--itlst;
	itelst--;
	itelst++;

	std::cout << "use both in while to print the lst" << std::endl;
	while (itlst != itelst)
	{
		std::cout << *itlst << std::endl;
		itlst++;
	}


	return 0;
}
