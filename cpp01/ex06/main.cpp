/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:39:25 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:13:19 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <filter level>" << std::endl;
        std::cout << "Filter levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    Harl harl;

    std::string filterLevel = argv[1];

    harl.filter(filterLevel);

    return 0;
}