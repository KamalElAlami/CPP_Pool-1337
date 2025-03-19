#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("you");
    AMateria* tmp;
    AMateria* tmp1;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp1 = src->createMateria("cure");
    me->equip(tmp1);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    delete tmp;
    delete tmp1;
    
    std::cout << "---------------------------------------" << std::endl;

    ICharacter	*character = new Character("bad character");
    IMateriaSource	*mas = new MateriaSource();
    mas->learnMateria(new Ice());
    mas->learnMateria(new Cure());
    AMateria	*new_materia;
    AMateria	*new_materia1;
    new_materia = mas->createMateria("ice");
    new_materia1 = mas->createMateria("cure");
    character->equip(new_materia);
    character->equip(new_materia1);
    character->use(0, *character);
    character->use(1, *character);
    character->unequip(0);
    character->unequip(1);
    delete character;
    delete mas;
    delete new_materia;
    delete new_materia1;
}