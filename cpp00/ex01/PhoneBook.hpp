#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        int     count;
        Contact contacts[8];
    public:
        PhoneBook();
        void    add_contact();
        void    search_contact();
        void    exit();
        string  ft_getline(void);
};

#endif
