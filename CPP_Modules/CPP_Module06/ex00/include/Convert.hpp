#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <cstring>
# include <cctype>
# include <limits> 
# include <cstdlib>

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
    const char *_science[4];
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
    float getValueAsDouble();

    int detectLiteralType() const;
    void parsingLiteralType();

    void parseToCharValue();
    void parseToIntValue();
    void parseToFloatValue();
    void parseToDoubleValue();
    void set_flag_if_inf_or_nan();

    bool isCharInput() const;
    bool isIntInput() const;
    bool isFloatInput() const;
    bool isDoubleInput() const;
    bool isOverflow(int type, char case_flag) const;
    bool isOverflow(int type, int case_flag) const;
    bool isOverflow(int type, float case_flag) const;
    bool isOverflow(int type, double case_flag) const;

    void parsingLiteralType(int type);

    void toCharAndPrint();
    void toIntAndPrint();
    void toFloatAndPrint();
    void toDoubleAndPrint();
    bool isAllZeroCharAfterIdx(size_t idx);

    void throwInfOrNan();

    class ImpossibleException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class InfException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NanException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NonDisplayableException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

};

#endif