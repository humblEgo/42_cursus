#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <random>
# include <cstdlib>
# include <limits>

typedef struct  Data
{
    std::string s1;
    int         n;
    std::string s2;
}               Data;

void *serialize(void);
Data *deserialize(void *raw);

#endif