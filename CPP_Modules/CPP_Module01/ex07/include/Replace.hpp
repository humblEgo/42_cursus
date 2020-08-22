#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

class Replace
{
private:
    /* data */
public:
    Replace();
    ~Replace();

    static void sed(std::string const &file, std::string const &target, std::string const &replace);
    static std::string changeTargetToReplace(std::string line, std::string const &target, std::string const &replace);
};

#endif