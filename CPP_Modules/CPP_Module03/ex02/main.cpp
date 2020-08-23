#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout<<"\n========================================"<<std::endl;
    std::cout<<"[Test FragTrap]"<<std::endl;

    std::string target = "Timo";
    FragTrap *rumble = new FragTrap("Rumble");
    // FragTrap *rumble2 = new FragTrap(*rumble);
    // FragTrap *rumble3 = new FragTrap("Rumbl3");
    // *rumble2 = *rumble3;
    // delete rumble2;
    // delete rumble3;

    std::cout<<"============================"<<std::endl;
    std::cout<<"|Welcome to summoner's rift|"<<std::endl;
    std::cout<<"|Minion has spawned.       |"<<std::endl;
    std::cout<<"============================"<<std::endl;
    rumble->rangedAttack(target);
    rumble->meleeAttack(target);
    std::cout<<"\n========================================";
    std::cout<<"Take damage"<<std::endl;
    std::cout<<target<<" attacked rumble!"<<std::endl;
    rumble->takeDamage(40);
    rumble->takeDamage(40);
    rumble->takeDamage(40);
    rumble->takeDamage(40);
    std::cout<<"\n========================================";
    std::cout<<"Be repaired"<<std::endl;
    std::cout<<"Zilean chrono shifts for rumble!"<<std::endl;
    rumble->beRepaired(30);
    rumble->beRepaired(30);
    rumble->beRepaired(30);
    rumble->beRepaired(30);
    rumble->beRepaired(30);
    std::cout<<"\n========================================";
    std::cout<<"Consume energy"<<std::endl;
    std::cout<<target<<" is laughing!"<<std::endl;
    rumble->vaulthunter_dot_exe(target);
    rumble->vaulthunter_dot_exe(target);
    rumble->vaulthunter_dot_exe(target);
    rumble->vaulthunter_dot_exe(target);
    rumble->vaulthunter_dot_exe(target);
    std::cout<<"An enemy has been slain. Legendary!"<<std::endl;
    std::cout<<target<<" can't laugh anymore.."<<std::endl;
    delete rumble;

    std::cout<<"\n========================================"<<std::endl;
    std::cout<<"[Test ScavTrap]"<<std::endl;

    ScavTrap *blitzcrank = new ScavTrap("Blitzcrank");
    std::cout<<target<<" is back!"<<std::endl;

    blitzcrank->meleeAttack(target);
    blitzcrank->rangedAttack(target);
    std::cout<<"\n========================================";
    std::cout<<"Take damage"<<std::endl;
    std::cout<<target<<" attacked blitzcrank!"<<std::endl;
    blitzcrank->takeDamage(40);
    blitzcrank->takeDamage(40);
    blitzcrank->takeDamage(40);
    blitzcrank->takeDamage(40);
    std::cout<<"\n========================================";
    std::cout<<"Be repaired"<<std::endl;
    std::cout<<"Zilean chrono shifts for blitzcrank!"<<std::endl;
    blitzcrank->beRepaired(30);
    blitzcrank->beRepaired(30);
    blitzcrank->beRepaired(30);
    blitzcrank->beRepaired(30);
    std::cout<<"\n========================================";
    std::cout<<"ChallengeNewcomer"<<std::endl;
    blitzcrank->challengeNewcomer();

    delete blitzcrank;
    
    return (0);
}