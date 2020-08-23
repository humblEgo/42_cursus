#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
    RadScorpion();
    virtual ~RadScorpion(void);
    virtual void takeDamage(int damage);
};

#endif