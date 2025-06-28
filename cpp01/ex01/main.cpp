/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:28:25 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:34:50 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int hordeSize = 5;
    std::string zombieName = "Horde Member";

    std::cout << "Creating a zombie horde of size " << hordeSize << std::endl;

    Zombie* horde = zombieHorde(hordeSize, zombieName);
    
    std::cout << "\nZombies announcing themselves:" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    std::cout << "\nDestroying the zombie horde:" << std::endl;
    delete[] horde;

    return 0;
}