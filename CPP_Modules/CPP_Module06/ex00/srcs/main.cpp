/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:57:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/27 19:39:13 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"Error: bad arguments"<<std::endl;
        return (1);
    }
    if (strlen(argv[1]) == 0)
    {
        std::cerr<<"Error: bad arguments"<<std::endl;
        return (1);
    }
    Convert converter(argv[1]);
    converter.toCharAndPrint();
    converter.toIntAndPrint();
    converter.toFloatAndPrint();
    converter.toDoubleAndPrint();
    return (0);
}