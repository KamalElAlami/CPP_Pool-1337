/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:15 by kael-ala          #+#    #+#             */
/*   Updated: 2024/12/30 14:21:18 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

using std::getline;

void add(void)
{
    PhoneBook   book;
    Contact     vectim;
    string fname;
    string lname;
    string nname;
    string num;
    string dark;

    cout << "First Name: ";
    getline(cin, fname);
    cout << "Last Name: ";
    getline(cin, lname);
    cout << "Nick Name: ";
    getline(cin, nname);
    cout << "Phone Number: ";
    getline(cin, num);
    cout << "Your Darkest Secret: ";
    getline(cin, dark);
    vectim.set_inputs(fname, lname, nname, num, dark);
    book.add_contact(vectim);
}

int main(void)
{
    string cmd;
    while (1)
    {
        cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        getline(cin, cmd);
        if (cmd.compare("ADD") == 0)
            add();
        else if (cmd.compare("SEARCH") == 0)
            cout << "Later.\n";
        else if (cmd.compare("EXIT") == 0)
            cout << "Later.\n";
        else
            cout << "Invalid command. Please use ADD, SEARCH, or EXIT.\n";
    }
}