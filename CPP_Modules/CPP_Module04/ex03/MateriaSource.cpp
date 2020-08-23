#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < SLOT_SIZE; i++)
        this->_sources[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (other._sources[i] == nullptr)
            this->_sources[i] = nullptr;
        else
            this->_sources[i] = other._sources[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (other._sources[i] == nullptr)
            this->_sources[i] = nullptr;
        else
            this->_sources[i] = other._sources[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (this->_sources[i] != nullptr)
            delete this->_sources[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (this->_sources[i] == nullptr)
        {
            this->_sources[i] = materia;
            return ;
        }
    }
    std::cout<<"Source slot is full"<<std::endl;
}