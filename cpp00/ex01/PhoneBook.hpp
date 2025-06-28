/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 15:23:15 by nkiampav          #+#    #+#             */
/*   Updated: 2025-02-08 15:23:15 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContacts() const;
    void displayContactDetails(int index) const;
private:
    std::string truncateString(const std::string& str) const;
};

#endif
