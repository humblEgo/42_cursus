#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define SLOT_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _sources[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(std::string const& type);
};

#endif