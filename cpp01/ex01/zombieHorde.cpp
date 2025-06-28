/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:27:11 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:35:37 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0) 
    {
        std::cerr << "Cannot create a horde with " << N << " zombies." << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    
    return horde;
}