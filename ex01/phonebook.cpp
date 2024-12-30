#include "phonebook.hpp"

PhoneBook::PhoneBook()
{}

void PhoneBook::add_contact(Contact new_one)
{
    if (count < 8)
    {
        count++;
        contacts[count].set_index(count);
        contacts[count] = new_one;
    }
    else
        count = 0;
}