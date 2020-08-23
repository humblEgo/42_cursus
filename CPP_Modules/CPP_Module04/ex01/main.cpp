#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
    // Character* me = new Character("me");

    // std::cout << *me;

    // Enemy* b = new RadScorpion();

    // AWeapon* pr = new PlasmaRifle();
    // AWeapon* pf = new PowerFist();

    // me->equip(pr);
    // std::cout << *me;
    // me->equip(pf);

    // me->attack(b);
    // std::cout << *me;
    // me->equip(pr);
    // std::cout << *me;
    // me->attack(b);
    // std::cout << *me;
    // me->attack(b);
    // std::cout << *me;

    std::cout<<"==================My test=================="<<std::endl;

    Character* me = new Character("me");
    Character* you = new Character("you");

    Enemy *rad_scorpion = new RadScorpion();
    Enemy *super_mutant = new SuperMutant();

    AWeapon *plasma_rifle = new PlasmaRifle();
    AWeapon *power_fist = new PowerFist();

    std::cout<<"\n================================Equip test"<<std::endl;
    std::cout<<*me;
    me->equip(plasma_rifle);
    std::cout<<*me;
    me->equip(power_fist);
    std::cout<<*me;
    me->equip(plasma_rifle);
    std::cout<<*me;
    you->equip(power_fist);
    std::cout<<*you;
    // *you = *me;

    std::cout<<me->getCurrentWeaponName()<<": ";
    std::cout<<"damage-> "<<me->getCurrentWeapon()->getDamage()<<std::endl;
    std::cout<<me->getCurrentWeaponName()<<": ";
    std::cout<<"APcost-> "<<me->getCurrentWeapon()->getAPCost()<<std::endl;

    std::cout<<you->getCurrentWeaponName()<<": ";
    std::cout<<"damage-> "<<you->getCurrentWeapon()->getDamage()<<std::endl;
    std::cout<<you->getCurrentWeaponName()<<": ";
    std::cout<<"APcost-> "<<you->getCurrentWeapon()->getAPCost()<<std::endl;


    std::cout<<"\n================================Attack test"<<std::endl;
    std::cout<<rad_scorpion->getType()<<"'s HP:"<<rad_scorpion->getHP()<<std::endl;  
    me->attack(rad_scorpion);
    me->attack(rad_scorpion);
    me->attack(rad_scorpion);
    me->attack(rad_scorpion);
    me->attack(rad_scorpion);
    std::cout<<*me;

    std::cout<<"\n================================AP test"<<std::endl;
    std::cout<<super_mutant->getType()<<"'s HP:"<<super_mutant->getHP()<<std::endl;  
    me->attack(super_mutant);
    me->attack(super_mutant);
    me->attack(super_mutant);
    me->attack(super_mutant);   // Not enough AP
    me->attack(super_mutant);   // Not enough AP
    std::cout<<super_mutant->getType()<<"'s HP:"<<super_mutant->getHP()<<std::endl;  
    
    std::cout<<*you;
    you->attack(super_mutant);
    you->attack(super_mutant);
    you->attack(super_mutant);

    std::cout<<*me;
    std::cout<<*you;
    delete (me);
    delete (you);
    delete (plasma_rifle);
    delete (power_fist);
    return (0);
}