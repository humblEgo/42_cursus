#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
    std::string name_;
    int         ap_;
    AWeapon     *current_weapon_;
public:
    Character(std::string const& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
    void recoverAP();
    void equip(AWeapon*);
    void attack(Enemy*);
    std::string const& getName() const;
    int const& getAP() const;
    std::string const getCurrentWeaponName() const;
    AWeapon *getCurrentWeapon() const;
};

std::ostream const& operator<<(std::ostream& out, Character& character);

#endif