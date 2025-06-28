/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:12:31 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/12 10:15:03 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating all types of robots ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    std::cout << "\n=== Testing attacks (different message) ===" << std::endl;
    clap.attack("Enemy1");
    scav.attack("Enemy2");
    frag.attack("Enemy3");

    std::cout << "\n=== Testing damage ===" << std::endl;
    clap.takeDamage(5);
    scav.takeDamage(30);
    frag.takeDamage(40);

    std::cout << "\n=== Testing repair ===" << std::endl;
    clap.beRapaired(3);
    scav.beRapaired(20);
    frag.beRapaired(25);

    std::cout << "\n=== Testing ScavTrap special ability ===" << std::endl;
    scav.guardGate();
    frag.highFiveGuys();

    std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
    {
        std::cout << "Creating temporary FragTrap:" << std::endl;
        FragTrap temp("Temporary");
        temp.highFiveGuys();
        std::cout << "Leaving scope - destructor chaining." << std::endl;
    }   // Destructor chaining will be shown here

    std::cout << "\n=== Testing more FragTrap funtionality ===" << std::endl;
    FragTrap powerhouse("Powerhouse");
    powerhouse.attack("Boss");
    powerhouse.highFiveGuys();
    powerhouse.takeDamage(50);
    powerhouse.beRapaired(30);
    powerhouse.highFiveGuys();

    std::cout << "\n=== Creating another FragTrap for more tests ===" << std::endl;
    FragTrap friendly("Friendly");
    friendly.highFiveGuys();

    std::cout << "\n=== Destructor will be called in reverse order ===" << std::endl;
    return 0;
}