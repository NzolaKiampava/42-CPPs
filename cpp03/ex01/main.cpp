/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:05:34 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/12 14:23:32 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTrap and ScavTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");

    std::cout << "\n=== Testing attacks (different message) ===" << std::endl;
    clap.attack("Enemy1");
    scav.attack("Enemy2");

    std::cout << "\n=== Testing damage ===" << std::endl;
    clap.takeDamage(5);
    scav.takeDamage(30);

    std::cout << "\n=== Testing repair ===" << std::endl;
    clap.beRapaired(3);
    scav.beRapaired(20);

    std::cout << "\n=== Testing ScavTrap special ability ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
    {
        ScavTrap temp("Temporary");
        temp.guardGate();
    }

    std::cout << "\n=== Testing more scavTrap funtionality ===" << std::endl;
    ScavTrap heavy("Heavy");
    heavy.attack("Target");
    heavy.guardGate();
    heavy.takeDamage(50);
    heavy.beRapaired(25);

    std::cout << "\n=== Destructor will be called in reverse order ===" << std::endl;
    return 0;
}