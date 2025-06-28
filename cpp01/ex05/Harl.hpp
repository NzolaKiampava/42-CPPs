/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:25:42 by nkiampav          #+#    #+#             */
/*   Updated: 2025/05/05 09:20:22 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef void (Harl::*MessageFunction)(void);

    static const std::string levels[4];
    static const MessageFunction functions[4];

public:
    Harl();
    ~Harl();

    void complain(std::string level);
};

#endif
