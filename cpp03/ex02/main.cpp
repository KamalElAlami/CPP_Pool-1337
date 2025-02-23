#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Destroyer");
    
    std::cout << "\n=== Testing Attack ===" << std::endl;
    frag.attack("Enemy Bot");
    frag.takeDamage(30);
    frag.beRepaired(20);
    
    std::cout << "\n=== Testing Special Function ===" << std::endl;
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing Energy Consumption ===" << std::endl;
    // Test multiple attacks to show energy consumption
    for(int i = 0; i < 5; i++) {
        frag.attack("Target");
    }
    
    std::cout << "\n=== Testing Damage and Repair ===" << std::endl;
    frag.takeDamage(95);
    frag.beRepaired(10);
    frag.takeDamage(50); // Should destroy the FragTrap
    frag.attack("Enemy"); // Should fail due to no HP
    
    std::cout << "\n=== End of Test ===" << std::endl;
    return 0;
}