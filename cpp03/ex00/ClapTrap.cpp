/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:17 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/11 10:56:30 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot attack because it has no hitPoints" << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot attack because it has no energyPoints" << std::endl;
        return ;
    }
    
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks "<< target
                << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= amount)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount
                    << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount
                << " points of damage! Hit points remaining: " << this->hitPoints << std::endl;
    }
}

void ClapTrap::beRapaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot be repaired because it's destroyed" << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot be repaired because it has no POints" << std::endl;
        return ;
    }
    
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
                << " hit points! current hit points: " << this->hitPoints << std::endl;
}