/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:15 by kael-ala          #+#    #+#             */
/*   Updated: 2024/12/31 11:02:56 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::getline;

void search()
{
    
}

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
            book.exit();
        else
            cout << "Invalid command. Please use ADD, SEARCH, or EXIT.\n";
    }
}