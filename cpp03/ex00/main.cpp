#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Testing Constructors ===" << std::endl;
    {
        std::cout << "\n1. Default Constructor:" << std::endl;
        ClapTrap default_trap;
        
        std::cout << "\n2. Parameterized Constructor:" << std::endl;
        ClapTrap named_trap("R2D2");
        
        std::cout << "\n3. Copy Constructor:" << std::endl;
        ClapTrap copy_trap(named_trap);
        
        std::cout << "\n4. Assignment Operator:" << std::endl;
        default_trap = named_trap;
    }
    
    std::cout << "\n=== Testing Attack Function ===" << std::endl;
    {
        ClapTrap attacker("Attacker");
        
        std::cout << "\n1. Normal attack:" << std::endl;
        attacker.attack("Target");
        
        std::cout << "\n2. Multiple attacks to drain energy:" << std::endl;
        for (int i = 0; i < 11; i++) {
            std::cout << "Attack " << i + 1 << ": ";
            attacker.attack("Target");
        }
    }
    
    std::cout << "\n=== Testing Damage Function ===" << std::endl;
    {
        ClapTrap victim("Victim");
        
        std::cout << "\n1. Take small damage:" << std::endl;
        victim.takeDamage(5);
        
        std::cout << "\n2. Take lethal damage:" << std::endl;
        victim.takeDamage(10);
        
        std::cout << "\n3. Try actions after death:" << std::endl;
        victim.attack("Someone");
        victim.beRepaired(5);
    }
    
    std::cout << "\n=== Testing Repair Function ===" << std::endl;
    {
        ClapTrap repairer("Repairer");
        
        std::cout << "\n1. Take damage then repair:" << std::endl;
        repairer.takeDamage(5);
        repairer.beRepaired(1);
        
        std::cout << "\n2. Multiple repairs to drain energy:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Repair " << i + 1 << ": ";
            repairer.beRepaired(1);
        }
    }
    
    std::cout << "\n=== Testing Complex Scenario ===" << std::endl;
    {
        ClapTrap warrior("Warrior");
        
        warrior.attack("Enemy1");
        warrior.takeDamage(5);
        warrior.beRepaired(2);
        warrior.attack("Enemy2");
        warrior.takeDamage(4);
        warrior.beRepaired(1);
        warrior.attack("Enemy3");
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}