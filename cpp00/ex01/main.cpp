/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:32:53 by nkiampav          #+#    #+#             */
/*   Updated: 2025/03/31 10:04:45 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            std::exit(0);
    } while (input.empty());
    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof() || command == "EXIT")
            break;
        
        if (command == "ADD") {
            Contact newContact;
            std::string fname = getInput("Enter first name: ");
            std::string lname = getInput("Enter last name: ");
            std::string nname = getInput("Enter nickname: ");
            std::string phone = getInput("Enter phone number: ");
            std::string secret = getInput("Enter darkest secret: ");
            
            newContact.setContact(fname, lname, nname, phone, secret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.searchContacts();
            std::cout << "Enter index to display details: ";
            std::string indexStr;
            std::getline(std::cin, indexStr);
            
            int index = 0;
            std::istringstream iss(indexStr);
            if (!(iss >> index)) {
                std::cout << "Invalid index!" << std::endl;
                continue;
            }
            phoneBook.displayContactDetails(index);
        }
    }
    return 0;
}
