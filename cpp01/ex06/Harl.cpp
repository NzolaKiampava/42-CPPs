/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:25:21 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:17:18 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const Harl::MessageFunction Harl::functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl() {}

Harl::~Harl() {}

int Harl::getLevelIndex(std::string level) const { 
    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level) {
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "[ UNKNOWN LEVEL ]" << std::endl;
    std::cout << "Harl doesn't know how to complain at level: " << level << std::endl;
    std::cout << std::endl;
}

void Harl::filter(std::string minLevel) {
    int minIndex = getLevelIndex(minLevel);
    
    if (minIndex == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    switch(minIndex) {
        case 0:
            (this->*functions[0]) ();
            // Fall through
        case 1:
            (this->*functions[1]) ();
            // Fall through  
        case 2:
            (this->*functions[2]) ();
            // Fall through 
        case 3:
            (this->*functions[3]) ();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}