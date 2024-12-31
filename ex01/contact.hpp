#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Contact
{
    private:
        int     index;
        string  firstname;
        string  lastname;
        string  nickname;
        string  phonenumber;
        string  darkestone;

    public:
        Contact ();
        void set_index(int n);
        void set_inputs(string fname, string lname, string nname, string num, string dark);
};

#endif