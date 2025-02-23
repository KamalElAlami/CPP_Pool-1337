#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Testing ScavTrap Constructors ===" << std::endl;
    {
        std::cout << "\n1. Default Constructor:" << std::endl;
        ScavTrap default_trap;
        
        std::cout << "\n2. Parameterized Constructor:" << std::endl;
        ScavTrap named_trap("Guardian");
        
        std::cout << "\n3. Copy Constructor:" << std::endl;
        ScavTrap copy_trap(named_trap);
        
        std::cout << "\n4. Assignment Operator:" << std::endl;
        default_trap = named_trap;
    }
    
    std::cout << "\n=== Testing ScavTrap Functions ===" << std::endl;
    {
        ScavTrap scav("Warrior");
        
        // Test attack
        std::cout << "\nTesting attack:" << std::endl;
        scav.attack("Enemy");
        
        // Test takeDamage
        std::cout << "\nTesting take damage:" << std::endl;
        scav.takeDamage(30);
        
        // Test beRepaired
        std::cout << "\nTesting repair:" << std::endl;
        scav.beRepaired(20);
        
        // Test guardGate
        std::cout << "\nTesting guard gate:" << std::endl;
        scav.guardGate();
    }
    
    std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
    {
        ScavTrap energy_test("EnergyTester");
        
        std::cout << "\nDepleting energy with attacks:" << std::endl;
        for (int i = 0; i < 52; i++) {  // ScavTrap has 50 energy points
            std::cout << "Attack " << i + 1 << ": ";
            energy_test.attack("Target");
        }
    }
    
    std::cout << "\n=== Testing Hit Points Depletion ===" << std::endl;
    {
        ScavTrap hp_test("HPTester");
        
        std::cout << "\nDepleting health:" << std::endl;
        hp_test.takeDamage(50);
        std::cout << "Attack after 50 damage: ";
        hp_test.attack("Target");
        
        hp_test.takeDamage(50);  // Should now be at 0 HP
        std::cout << "Attack after 0 HP: ";
        hp_test.attack("Target");
        
        std::cout << "Trying to repair at 0 HP: ";
        hp_test.beRepaired(10);
    }
    
    std::cout << "\n=== Testing Mixed Actions ===" << std::endl;
    {
        ScavTrap mixed("MixedTester");
        
        mixed.attack("Enemy1");
        mixed.guardGate();
        mixed.takeDamage(20);
        mixed.beRepaired(10);
        mixed.attack("Enemy2");
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}