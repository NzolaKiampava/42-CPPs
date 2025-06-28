/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:49:47 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/14 15:39:54 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Testing Abstract class ===\n";

    std::cout << "Note: Cannot create Animal object diretly - It's abstract!" << std::endl;
    
    std::cout << "\n=== Testing polymorphism with abstract base ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << ": ";
    j->makeSound();
    std::cout << i->getType() << ": ";
    i->makeSound();
    
    delete j;   //should not create a leak
    delete i;

    std::cout << "\n=== Array Test with Abstract Base ===" << std::endl;

    const int arraySize = 4;
    Animal* animals[arraySize];

    // Fill half with Dogs, half with Cats
    for (int idx = 0; idx < arraySize; idx++) 
    {
        if (idx < arraySize / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << "\n--- Testing sounds ---" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
        delete animals[idx];

    std::cout << "\n=== Deep Copy Test with Abstract Base ===" << std::endl;
    
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I'm thinking about bones!");
    originalDog.getBrain()->setIdea(1, "Abstract classes are cool!");

    Dog copiedDog(originalDog);

    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    // Modify original to prove they are independent
    originalDog.getBrain()->setIdea(0, "I changed my abstract mind!");

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog ideia 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

        
    std::cout << "\nBrain addresses are different: " << (originalDog.getBrain() != copiedDog.getBrain() ? "YES" : "NO") << std::endl;
    
    return 0;
}