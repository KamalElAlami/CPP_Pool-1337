/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:15 by kael-ala          #+#    #+#             */
/*   Updated: 2024/10/16 11:40:10 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    string cmd;
    while (1)
    {
        cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        cin >> cmd;
        if (cmd.compare("ADD") != 0 && cmd.compare("SEARCH") != 0 && cmd.compare("EXIT") != 0)
            cout << "Invalid command. Please use ADD, SEARCH, or EXIT.\n";
        else
            cout << "good job \n";
    }
}