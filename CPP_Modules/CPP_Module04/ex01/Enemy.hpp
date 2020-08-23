#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
private:
    int                 hp_;
    std::string const   type_;
public:
    Enemy(int hp, std::string const& type);
    virtual ~Enemy(void);
    std::string const& getType() const;
    int getHP() const;

    virtual void takeDamage(int);
};

#endif