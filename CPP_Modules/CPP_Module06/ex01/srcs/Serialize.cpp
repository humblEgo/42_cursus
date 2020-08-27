#include "Serialize.hpp"

void *serialize()
{
    std::string alphabet;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> pick(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    char *raw = nullptr;

    alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    raw = new char[20];
    for (size_t i = 0; i < 8; i++)
        raw[i] = alphabet[std::abs(pick(gen)) % alphabet.length()];
    *reinterpret_cast<int*>(raw + 8) = pick(gen);
    for (size_t i = 13; i < 20; i++)
        raw[i] = alphabet[std::abs(pick(gen)) % alphabet.length()];
    return (reinterpret_cast<void*>(raw));
}

Data *deserialize(void *raw)
{
    Data* ret = nullptr;

    ret = new Data;
    ret->s1 = std::string(static_cast<char *>(raw), 8);
    ret->n = *reinterpret_cast<int*>(static_cast<char *>(raw) + 8);
    ret->s2 = std::string(static_cast<char *>(raw) + 12, 8);
    return (ret);
}