#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
    // {
    //     Weapon club = Weapon("crude spiked club");
    //     HumanA bob("Bob", club);
    //     bob.attack();
    //     club.setType("some other type of club");
    //     bob.attack();
    // }
    // {
    //     Weapon club = Weapon("crude spiked club");
    //     HumanB jim("Jim");
    //     jim.take_weapon(club);
    //     jim.attack();
    //     club.setType("some other type of club");
    //     jim.attack();
    // }
    {
        Weapon a("zerwata");
        HumanB b("");
        // b.take_weapon(a);
        b.attack();
        
    }
    return 0;
}