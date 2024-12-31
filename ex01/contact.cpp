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
int Contact::get_index(void)
{
	return index;
}
string Contact::get_fname(void)
{
	return firstname;
}
string Contact::get_lname(void)
{
	return lastname;
}
string Contact::get_nname(void)
{
	return nickname;
}
string Contact::get_phone(void)
{
	return phonenumber;
}
string Contact::get_darkestone(void)
{
	return darkestone;
}