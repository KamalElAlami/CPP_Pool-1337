#include "PhoneBook.hpp"

string	PhoneBook::ft_getline(void)
{
	string temp;
	if (!getline(cin, temp))
		exit();
	return (temp);
}

PhoneBook::PhoneBook()
{
	count = 0;
}

void	PhoneBook::exit()
{
	cout << endl << "Exiting......." << endl;
	std::exit(0);
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
		fname = ft_getline();
		cout << "Last Name: ";
		lname = ft_getline();
		cout << "Nick Name: ";
		nname = ft_getline();
		cout << "Phone Number: ";
		num = ft_getline();
		cout << "Your Darkest Secret: ";
		dark = ft_getline();
		if (fname.empty() || lname.empty() || nname.empty() || num.empty() || dark.empty())
			cout << "Empty fields is not allowed\n";
	}

	if (count >= 8)
		count = 0;
	contacts[count].set_inputs(fname, lname, nname, num, dark);
	contacts[count].set_index(count);
	count++;
}
static string large_str(string word)
{
	string new_word;

	if (word.length() >= 10)
		new_word = word.substr(0, 9) + '.';
	else
		new_word = word;
	return (new_word);
}
static void print_contact(Contact contact[], int index)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	while (contact[i].get_index() != -1 && contact[i].get_index() < 8)
	{
		if (contact[i].get_index() == index)
		{
			cout << "Index          : " << contact[i].get_index() << endl;
			cout << "First Name     : " << contact[i].get_fname() << endl;
			cout << "Last Name      : " << contact[i].get_lname() << endl;
			cout << "Nick Name      : " << contact[i].get_nname() << endl;
			cout << "Phone Number   : " << contact[i].get_phone() << endl;
			cout << "Darkest Secret : " << contact[i].get_darkestone() << endl;
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
		cout << "Invalid Index" << endl;
	
}

void    PhoneBook::search_contact()
{
	string input;
	int i;

	i = 0;
	cout << "---------------------------------------------" << endl;
	cout << "|     index| firstname|  lastname|  nickname|" << endl;
	while (contacts[i].get_index() != -1 && contacts[i].get_index() < 8)
	{
		cout << '|' << setw(10) << contacts[i].get_index();
		cout << '|' << setw(10) << large_str(contacts[i].get_fname());
		cout << '|' << setw(10) << large_str(contacts[i].get_lname());
		cout << '|' << setw(10) << large_str(contacts[i].get_nname()) << '|' << endl;
		i++;
	}
	cout << "---------------------------------------------" << endl;
	while (input.empty())
	{
		cout << "Enter Contact Index : ";
		input = ft_getline();
	}
	int res = atoi(input.c_str());
	if (res == 0 && input != "0")
		res = -1;
	print_contact(contacts, res);
}