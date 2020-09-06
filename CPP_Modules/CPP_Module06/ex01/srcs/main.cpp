/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:13:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:13:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
    void *raw = nullptr;
    Data *data = nullptr;

    raw = serialize();
    data = deserialize(raw);

    std::cout << "=====test 1=====" << std::endl;
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    std::cout << data->s2 << std::endl;

    if (raw != nullptr)
        delete static_cast<char *>(raw);
    if (data != nullptr)
        delete data;

    raw = serialize();
    data = deserialize(raw);

    std::cout << "=====test 2=====" << std::endl;
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    std::cout << data->s2 << std::endl;

    if (raw != nullptr)
        delete static_cast<char *>(raw);
    if (data != nullptr)
        delete data;

    raw = serialize();
    data = deserialize(raw);

    std::cout << "=====test 3=====" << std::endl;
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    std::cout << data->s2 << std::endl;

    if (raw != nullptr)
        delete static_cast<char *>(raw);
    if (data != nullptr)
        delete data;

    return (0);
}