/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:35:43 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:37:25 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class   Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
