#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
private:
    int count_;
    ISpaceMarine** units_;
public:
    Squad();
    Squad(const Squad& other);
    virtual Squad& operator=(const Squad& other);
    ~Squad();
    int getCount() const;
    ISpaceMarine* getUnit(int idx) const;
    int push(ISpaceMarine *unit);
    void deleteCurrentUnits();
    bool isAlreadyIn(ISpaceMarine *unit) const;
};

#endif