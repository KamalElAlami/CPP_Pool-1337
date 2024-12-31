#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
}

void PhoneBook::add_contact()
{
	string fname;
	string lname;
	string nname;
	string num;
	string dark;

	while (fname.empty() || lname.empty() || nname.empty() || num.empty() || dark.empty())
	{
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
		if (fname.empty() || lname.empty() || nname.empty() || num.empty() || dark.empty())
			cout << "Empty fields is not allowed\n";
	}

	if (count >= 8)
		count = 0;
	contacts[count].set_inputs(fname, lname, nname, num, dark);
	contacts[count].set_index(count);
	count++;
}

void    PhoneBook::search_contact()
{
	int i;

	i = 0;
	cout << "-----------------------------------------" << endl;
	cout << "| index | firstname | lastname | nickname |" << endl;
	while (contacts[i].get_index() != -1)
	{
		cout << contacts[i].get_index() << '|' << contacts[i].get_fname() << '|' << contacts[i].get_lname() << '|' << contacts[i].get_nname() << endl;
		i++;
	}
	cout << "-----------------------------------------" << endl;
}