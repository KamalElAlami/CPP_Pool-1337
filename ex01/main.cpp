/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:15 by kael-ala          #+#    #+#             */
/*   Updated: 2025/01/02 11:54:44 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    string cmd;
    
    while (1)
    {
        cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        cmd = book.ft_getline();
        if (cmd == "ADD")
            book.add_contact();
        else if (cmd == "SEARCH")
            book.search_contact();
        else if (cmd == "EXIT")
            book.exit();
        else
            cout << "Invalid command. Please use ADD, SEARCH, or EXIT.\n";
    }
}