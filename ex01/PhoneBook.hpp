/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:07:41 by kael-ala          #+#    #+#             */
/*   Updated: 2024/10/22 11:48:42 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Contact
{
    private:
        int index;
        string firstname;
        string lastname;
        string nickname;
    public:
        Contact (string fname, string lname, string nname)
        {
            firstname = fname;
            lastname = lname;
            nickname = nname;
        }
        void set_index(int n){index = n;}
};

class PhoneBook
{
    private:
        Contact contacts[8];
    public:
        void add_contact(Contact new_one)
        {
            static int count;
            if (count < 8)
            {
                contacts[count++].set_index(count);
                contacts[count] = new_one;
            }
            else
                count = 0;
        }
        void search_book()        
    
};

#endif
