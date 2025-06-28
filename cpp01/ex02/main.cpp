/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:37:25 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:33:17 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;

    std::string& stringREF = brain;

    std::cout << "Memory addresses:" << std::endl;
    std::cout << "- Address of string variable: " << &brain << std::endl;
    std::cout << "- Address held by stringPTR:  " << stringPTR << std::endl;
    std::cout << "- Address held by stringREF:  " << &stringREF << std::endl;

    std::cout << "\nValues:" << std::endl;
    std::cout << "- Value of string variable: " << brain << std::endl;
    std::cout << "- Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "- Value referenced by stringREF: " << stringREF << std::endl;
}
