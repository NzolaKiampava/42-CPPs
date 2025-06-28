/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:49:47 by nkiampav          #+#    #+#             */
/*   Updated: 2025/06/14 15:07:21 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Basic Test from Subject ===\n";
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;   //should not create a leak
    delete i;

    std::cout << "\n=== Array Test ===" << std::endl;

    const int arraySize = 0;
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

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I want to play fetch!");
    originalDog.getBrain()->setIdea(1, "Where is my bone?");

    std::cout << "\n--- Testing Dog deep copy ---" << std::endl;
    Dog copiedDog(originalDog);

    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    // Modify original to prove they are independent
    originalDog.getBrain()->setIdea(0, "I changed my mind!");

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog ideia 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Testing Cat deep copy ---" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I love fish!");
    originalCat.getBrain()->setIdea(1, "Time for a nap");
    
    Cat copiedCat;
    copiedCat = originalCat;   //Test assignment operator
    
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    
    // Modify original to prove they are independent
    originalCat.getBrain()->setIdea(0, "I prefer chicken now!");

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n--- Testing brain address independence ---" << std::endl;
    std::cout << "Original dog brain address: " << originalDog.getBrain() << std::endl;
    std::cout << "Copied dog brain address: " << copiedCat.getBrain() << std::endl;
    std::cout << "Addresses are different: " << (originalDog.getBrain() != copiedDog.getBrain() ? "YES" : "NO") << std::endl;
    
    return 0;
}