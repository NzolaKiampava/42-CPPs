/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:38:02 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:36:58 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "Creating a heap zombie:" << std::endl;
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();

    std::cout << "\nCreating a stack zombie:" << std::endl;
    randomChump("Stacky");

    std::cout << "\nDeleting the heap zombie:" << std::endl;
    delete heapZombie;

    return 0;
}
