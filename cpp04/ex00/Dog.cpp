/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:03:51 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/13 15:58:37 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy construcctor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment generic called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wouff! Wouff!" << std::endl;
}