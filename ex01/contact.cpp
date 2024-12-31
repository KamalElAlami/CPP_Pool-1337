#include "contact.hpp"

Contact::Contact()
{
	index = -1;
}
void Contact::set_index(int n)
{
	index = n;
}
void Contact::set_inputs(string fname, string lname, string nname, string num, string dark)
{
	firstname = fname;
	lastname = lname;
	nickname = nname;
	phonenumber = num;
	darkestone = dark;
}