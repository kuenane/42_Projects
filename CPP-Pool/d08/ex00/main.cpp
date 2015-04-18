// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 15:34:56 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 19:55:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "easyfind.hpp"

int		main(void)
{

	/* VECTOR */
	std::vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	std::cout << "search 2 in vector {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::vector<int> >(vect, 2);
	std::cout << std::endl;
	std::cout << "search 0 in vector {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::vector<int> >(vect, 0);
	std::cout << std::endl;

	/* LIST */
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	std::cout << "search 2 in list {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::list<int> >(lst, 2);
	std::cout << std::endl;
	std::cout << "search 0 in list {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::list<int> >(lst, 0);
	std::cout << std::endl;

	/* DEQUE */
	std::deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	std::cout << "search 2 in deque {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::deque<int> >(dq, 2);
	std::cout << std::endl;
	std::cout << "search 0 in deque {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::deque<int> >(dq, 0);
	std::cout << std::endl;

	/* SET */
	std::set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(3);
	std::cout << "search 2 in set {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::set<int> >(st, 2);
	std::cout << std::endl;
	std::cout << "search 0 in set {1, 2, 3}" << std::endl;
	std::cout << "result : ";
	easyfind< std::set<int> >(st, 0);
	std::cout << std::endl;

	/* MAP */
	std::map<int, int> mp;

	mp.insert(std::pair<int,int>(1, 1));
	mp.insert(std::pair<int,int>(2, 2));
	mp.insert(std::pair<int,int>(3, 3));
	std::cout << "search 2 in map {1->1, 2->2, 3->3}" << std::endl;
	std::cout << "result : ";
	easyfind<int>(mp, 2);
	std::cout << std::endl;
	std::cout << "search 0 in map {1->1, 2->2, 3->3}" << std::endl;
	std::cout << "result : ";
	easyfind<int>(mp, 0);

	return (0);
}
