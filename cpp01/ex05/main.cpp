/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:56:07 by nkiampav          #+#    #+#             */
/*   Updated: 2025/04/24 09:00:21 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "Testing Harl's complaints at different levels:" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "Testing with an invalid level:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    harl.complain("CRITICAL");

    return 0;
}