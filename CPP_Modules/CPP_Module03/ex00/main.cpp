#include "FragTrap.hpp"

int main(void)
{
    FragTrap rumble("Rumble");
    std::string target = "Timo";

    std::cout<<"============================"<<std::endl;
    std::cout<<"|Welcome to summoner's rift|"<<std::endl;
    std::cout<<"|Minion has spawned.       |"<<std::endl;
    std::cout<<"============================"<<std::endl;
    rumble.rangedAttack(target);
    rumble.meleeAttack(target);
    std::cout<<"\n========================================";
    std::cout<<"Take damage"<<std::endl;
    std::cout<<target<<" attacked rumble!"<<std::endl;
    rumble.takeDamage(40);
    rumble.takeDamage(40);
    rumble.takeDamage(40);
    rumble.takeDamage(40);
    std::cout<<"\n========================================";
    std::cout<<"Be repaired"<<std::endl;
    std::cout<<"Zilean chrono shifts for rumble!"<<std::endl;
    rumble.beRepaired(30);
    rumble.beRepaired(30);
    rumble.beRepaired(30);
    rumble.beRepaired(30);
    rumble.beRepaired(30);
    std::cout<<"\n========================================";
    std::cout<<"Consume energy"<<std::endl;
    std::cout<<target<<" is laughing!"<<std::endl;
    rumble.vaulthunter_dot_exe(target);
    rumble.vaulthunter_dot_exe(target);
    rumble.vaulthunter_dot_exe(target);
    rumble.vaulthunter_dot_exe(target);
    rumble.vaulthunter_dot_exe(target);
    std::cout<<"An enemy has been slain. Legendary!"<<std::endl;
    std::cout<<target<<" can't laugh anymore.."<<std::endl;

    return (0);
}