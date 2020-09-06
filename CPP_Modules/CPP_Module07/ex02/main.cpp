/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:12:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:12:42 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.ipp"

template <class T>
void print(Array<T> &arr)
{
	try
	{
		for (unsigned int i = 0; i < arr.size() + 1; i++)
			std::cout << (arr[i]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "Below test's are made by sanam. Thanks!" << std::endl;
	std::cout << "\n===================int test=====================" << std::endl;
	Array<int> int_test(10);
	for (size_t i = 0; i < 10; i++)
		int_test[i] = i;
	print(int_test);

	std::cout << "\n===================char test=====================" << std::endl;
	Array<char> char_test(10);
	for (int i = 0; i < 10; i++)
		char_test[i] = 'a' + i;
	print(char_test);

	std::cout << "\n====================copy test===================" << std::endl;
	Array<int> copy_int_test(int_test);
	std::cout << "==== copy_int_test ====" << std::endl;
	print(copy_int_test);
	std::cout << "==== copy_int_test[0 && 9] = 100 ====" << std::endl;
	copy_int_test[0] = 100;
	copy_int_test[9] = 100;
	print(copy_int_test);
	std::cout << "==== int_test ====" << std::endl;
	print(int_test);

	std::cout << "\n====================assign test===================" << std::endl;
	Array<int> assign_int_test;
	assign_int_test = copy_int_test;
	std::cout << "==== assign_int_test ====" << std::endl;
	print(assign_int_test);
	std::cout << "==== assign_int_test[0] = 10000 ====" << std::endl;
	assign_int_test[0] = 10000;
	print(assign_int_test);
	std::cout << "==== test2 ====" << std::endl;
	print(copy_int_test);

	std::cout << "\n==================== default constructor try-catch===============" << std::endl;
	Array<int> test4;
	try
	{
		test4[0];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}