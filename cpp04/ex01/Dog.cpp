/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:03:51 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/14 15:12:13 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy construcctor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment generic called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wouff! Wouff!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}