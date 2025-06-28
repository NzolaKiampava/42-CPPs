/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:46 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/12 12:51:33 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap robot1("R2D2");
    ClapTrap robot2("C3P0");

    std::cout << "\n=== Testing attacks ===" << std::endl;
    robot1.attack("Enemy1");
    robot2.attack("Enemy2");

    std::cout << "\n=== Testing damage ===" << std::endl;
    robot1.takeDamage(5);
    robot2.takeDamage(8);
    
    std::cout << "\n=== Testing repair ===" << std::endl;
    robot1.beRapaired(1);
    robot2.beRapaired(2);
    
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    robot1.takeDamage(1); // should destroy robot1
    robot1.attack("Enemy3"); // should fail - no hit points
    robot1.beRapaired(5);   // should fail - destroyed

    // Drain energy points
    std::cout << "\n=== Draining energy ===" << std::endl;
    for (int i = 0; i < 10; i++)
        robot2.attack("Target");

    robot2.attack("Final Target");  // should fail - no energy
    robot2.beRapaired(1);           // should fail - no energy

    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}
