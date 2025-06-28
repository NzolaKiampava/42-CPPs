/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:27:43 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/14 15:53:53 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal& other){
    std::cout << "Animal copy constructor called" << std::endl;
    type = other.type;
}

Animal& Animal::operator=(const Animal& other){
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
