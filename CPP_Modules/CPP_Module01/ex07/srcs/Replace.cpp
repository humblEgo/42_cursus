#include "Replace.hpp"

Replace::Replace()
{
}

Replace::~Replace()
{
}

std::string Replace::changeTargetToReplace(std::string line, std::string const &target, std::string const &replace)
{
    std::string result = line;
    std::string::size_type pos = 0;
    std::string::size_type offset = 0;

    while ((pos = result.find(target, offset)) != std::string::npos)
    {
        result.replace(result.begin() + pos, result.begin() + pos + target.size(), replace);
        offset = pos + replace.size();
    }
    return (result);
}

void Replace::sed(std::string const &file, std::string const &target, std::string const &replace)
{
    std::ifstream original_file;
    std::ofstream replaced_file;
    std::string line;
    std::string replacedLine;

    if (file.length() == 0 || target.length() == 0 || replace.length() == 0)
        throw ("Empty argument.");
    original_file.open(file);
    if (!original_file.is_open())
        throw ("Can't open input file.");
    replaced_file.open(file + ".replace", std::ios::trunc);
    if (!replaced_file.is_open())
        throw ("Can't open output file.");
    while (std::getline(original_file, line))
    {
        replaced_file<<Replace::changeTargetToReplace(line, target, replace);
        if (!original_file.eof())
            replaced_file<<std::endl;
    }
    original_file.close();
    replaced_file.close();
}