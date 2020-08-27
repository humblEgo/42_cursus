#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <cstring>
# include <cctype>
# include <limits> 

class Convert
{
private:
    std::string _input;
    char    _cvalue;
    int     _ivalue;
    float   _fvalue;
    double  _dvalue;
    int     _type;
    int     _flags[4];
    std::string _science[4] = {
        "inf",
        "nan",
        "inff",
        "nanf"
    };
    enum literalType
    {
        TYPE_CHAR = 0,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_INVALID  // 4
    };
    enum Flag
    {
        NORMAL_FLAG = 0,
        INF_FLAG,
        NAN_FLAG,
        OVERFLOW_FLAG
    };
public:
    Convert(std::string input);
    virtual ~Convert();
    Convert(const Convert& other);
    Convert& operator=(const Convert& other);

    std::string getInput() const;
    int getInputType() const;
    char getCharValue() const;
    int getIntValue() const;
    float getFloatValue() const;
    double getDoubleValue() const;

    char getValueAsChar();
    int getValueAsInt();
    float getValueAsFloat();

    int detectLiteralType() const;
    void parsingLiteralType();

    void parseToCharValue(std::stringstream& ss);
    void parseToIntValue(std::stringstream& ss);
    void parseToFloatValue(std::stringstream& ss);
    void parseToDoubleValue(std::stringstream& ss);
    void set_flag_if_inf_or_nan();

    bool isCharInput() const;
    bool isIntInput() const;
    bool isFloatInput() const;
    bool isDoubleInput() const;

    void parsingLiteralType(int type);

    void toCharAndPrint();
    void toIntAndPrint();
    void toFloatAndPrint();
    bool isAllZeroCharAfterIdx(size_t idx);
};

#endif