/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:15 by kael-ala          #+#    #+#             */
/*   Updated: 2025/01/01 04:23:19 by kael-ala         ###   ########.fr       */
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
        getline(cin, cmd);
        if (cmd == "ADD")
            book.add_contact();
        else if (cmd == "SEARCH")
            book.search_contact();
        else if (cmd == "EXIT")
            // book.exit();
            exit(1);
        else
            cout << "Invalid command. Please use ADD, SEARCH, or EXIT.\n";
    }
}