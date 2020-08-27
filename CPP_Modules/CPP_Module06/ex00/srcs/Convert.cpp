#include "Convert.hpp"

Convert::Convert(std::string input)
: _input(input)
{
    for (int i = TYPE_CHAR; i < TYPE_DOUBLE; i++)
        this->_flags[i] = NORMAL_FLAG;
    this->_type = detectLiteralType();
    parsingLiteralType();
}

Convert::~Convert()
{
}

Convert::Convert(const Convert& other)
: _input(other.getInput())
{
}

Convert& Convert::operator=(const Convert& other)
{
    this->_input = other.getInput();
    this->_type = other.getInputType();
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string Convert::getInput() const
{
    return (this->_input);
}

int Convert::getInputType() const
{
    return (this->_type);
}

char Convert::getCharValue() const
{
    return (this->_cvalue);
}

int Convert::getIntValue() const
{
    return (this->_ivalue);
}

float Convert::getFloatValue() const
{
    return (this->_fvalue);
}

double Convert::getDoubleValue() const
{
    return (this->_dvalue);
}

/*==========================================================*/
/*###################  Setter functions  ###################*/
/*==========================================================*/

int Convert::detectLiteralType() const
{
    int type;

    if (this->isCharInput())
        type = TYPE_CHAR;
    else if (this->isIntInput())
        type = TYPE_INT;
    else if (this->isFloatInput())
        type = TYPE_FLOAT;
    else if (this->isDoubleInput())
        type = TYPE_DOUBLE;
    else
        type = TYPE_INVALID;
    return (type);
}

void Convert::parsingLiteralType()
{
    std::stringstream ss;

    ss << this->getInput();
    int type = this->getInputType();
    if (type == TYPE_CHAR)
        parseToCharValue(ss);
    else if (type == TYPE_INT)
        parseToIntValue(ss);
    else if (type == TYPE_FLOAT)
        parseToFloatValue(ss);
    else if (type == TYPE_DOUBLE)
        parseToDoubleValue(ss);
    else if (type == TYPE_INVALID)
        set_flag_if_inf_or_nan();
}

void Convert::parseToCharValue(std::stringstream& ss)
{
    char check_limit;

    ss >> check_limit;
    this->_cvalue = check_limit;
    if (ss.fail() || check_limit > std::numeric_limits<char>::max() || check_limit < std::numeric_limits<char>::min())
        this->_flags[TYPE_CHAR] = OVERFLOW_FLAG;
}

void Convert::parseToIntValue(std::stringstream& ss)
{
    long check_limit;
    ss >> check_limit;
    this->_ivalue = check_limit;
    if (ss.fail() || check_limit > std::numeric_limits<int>::max() || check_limit < std::numeric_limits<int>::min())
        this->_flags[TYPE_INT] = OVERFLOW_FLAG;
}

void Convert::parseToFloatValue(std::stringstream& ss)
{
    float check_limit;
    ss >> check_limit;
    this->_fvalue = check_limit;
    if (ss.fail() 
        || check_limit > std::numeric_limits<float>::max() 
        || check_limit < std::numeric_limits<float>::min())
        this->_flags[TYPE_FLOAT] = OVERFLOW_FLAG;
}

void Convert::parseToDoubleValue(std::stringstream& ss)
{
    double check_limit;
    ss >> check_limit;
    this->_dvalue = check_limit;
    if (ss.fail() 
        || check_limit > std::numeric_limits<double>::max() 
        || check_limit < std::numeric_limits<double>::min())
        this->_flags[TYPE_DOUBLE] = OVERFLOW_FLAG;
}

void Convert::set_flag_if_inf_or_nan()
{
    std::string tmp = this->getInput();
    if ((tmp[0] == '+' || tmp[0] == '-') && tmp.length() == 4)
        tmp = tmp.substr(0);
    if (tmp.length() == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            if (tmp == _science[i] && i % 2 == 1)
            {
                this->_flags[TYPE_FLOAT] = INF_FLAG;
                this->_flags[TYPE_DOUBLE] = INF_FLAG;
            }
            else if (tmp == _science[i] && i % 2 == 0)
            {
                this->_flags[TYPE_FLOAT] = NAN_FLAG;
                this->_flags[TYPE_DOUBLE] = NAN_FLAG;
            }
        }
    }
}

bool Convert::isCharInput() const
{
    std::string tmp; 
    
    tmp = this->getInput();
    if (tmp.length() == 1 && !isdigit(tmp[0]))
        return (true);
    return (false);
}

bool Convert::isIntInput() const
{
    std::string tmp;
    size_t i;

    tmp = this->getInput();
    i = 0;
    if (tmp[i] == '-' || tmp[i] == '+')
        i++;
    for (; i < tmp.length(); i++)
    {
        if (!isdigit(tmp[i]))
            return (false);
    }
    return (true);
}

bool Convert::isFloatInput() const
{
    std::string tmp;
    size_t i;
    size_t len;
    size_t min_len;

    tmp = this->getInput();
    len = tmp.length();
    i = 0;
    min_len = 4;
    if (tmp[i] == '-' || tmp[i] == '+')
    {
        i++;
        min_len++;
    }
    if (len >= min_len)
    {
        if (tmp[i] == '0' && tmp[++i] == '.')
            i++;
        else
        {
            while (isdigit(tmp[i]))
                i++;
            if (tmp[i] == '.')
                i++;
        }
        while (isdigit(tmp[i]))
            i++;
        if (tmp[i] == 'f' && i == tmp.length() - 1)
            return (true);
    }
    return (false);
}

bool Convert::isDoubleInput() const
{
    std::string tmp;
    int i;
    int len;
    int min_len;

    tmp = this->getInput();
    i = 0;
    len = tmp.length();
    min_len = 3;
    if (tmp[i] == '-' || tmp[i] == '+')
    {
        i++;
        min_len = 4;
    }
    if (len >= min_len)
    {
        if (tmp[i] == '0' && tmp[++i] == '.')
            i++;
        else
        {
            while (isdigit(tmp[i]))
                i++;
            if (tmp[i] == '.')
                i++;
        }
        while (isdigit(tmp[i]))
            i++;
        if (len == i)
            return (true);
    }
    return (false);
}

char Convert::getValueAsChar()
{
    char ret;

    ret = '\0';
    int type = this->getInputType();
    if (type == TYPE_INVALID)
        throw "impossible";
    else if (type == TYPE_CHAR)
        ret = getCharValue();
    else if (type == TYPE_INT)
        ret = static_cast<char>(getIntValue());
    else if (type == TYPE_FLOAT)
        ret = static_cast<char>(getFloatValue());
    else if (type == TYPE_DOUBLE)
        ret = static_cast<char>(getDoubleValue());
    if (!isprint(ret))
        throw "Non displayable";
    return (ret);
}

int Convert::getValueAsInt()
{
    int ret;

    ret = 0;
    int type = this->getInputType();
    if (type == TYPE_INVALID)
        throw "impossible";
    else if (type == TYPE_CHAR)
        ret = static_cast<int>(getCharValue());
    else if (type == TYPE_INT)
        ret = getIntValue();
    else if (type == TYPE_FLOAT)
        ret = static_cast<int>(getFloatValue());
    else if (type == TYPE_DOUBLE)
        ret = static_cast<int>(getDoubleValue());
    return (ret);
}

float Convert::getValueAsFloat()
{
    float ret;

    ret = 0.0;
    int type = this->getInputType();
    if (type == TYPE_INVALID)
        throw "impossible";
    else if (type == TYPE_CHAR)
        ret = static_cast<float>(getCharValue());
    else if (type == TYPE_INT)
        ret = static_cast<float>(getIntValue());
    else if (type == TYPE_FLOAT)
        ret = getFloatValue();
    else if (type == TYPE_DOUBLE)
        ret = static_cast<float>(getDoubleValue());
    return (ret);
}

void Convert::toCharAndPrint()
{
    std::string ret;
    char char_value;

    ret = "char: ";
    try
    {
        char_value = this->getValueAsChar();
        std::cout<<ret<<char_value<<std::endl;
    }
    catch(const char *e)
    {
        ret += e;
        std::cout<<ret<<std::endl;
    }
}

void Convert::toIntAndPrint()
{
    std::string ret;
    int int_value;

    ret = "int: ";
    try
    {
        int_value = this->getValueAsInt();
        std::cout<<ret<<int_value<<std::endl;
    }
    catch(const char *e)
    {
        ret += e;
        std::cout<<ret<<std::endl;
    }
}

void Convert::toFloatAndPrint()
{
    std::string ret;
    float float_value;

    ret = "float: ";
    try
    {
        float_value = this->getValueAsFloat();
        size_t idx = this->getInput().find('.');
        std::string suffix = "";
        
        if (idx == std::string::npos || isAllZeroCharAfterIdx(idx))
            suffix = ".0f";
        else
            suffix = "f";
        std::cout<<ret<<float_value<<suffix<<std::endl;
    }
    catch(const char *e)
    {
        ret += e;
        std::cout<<ret<<std::endl;
    }
}

bool Convert::isAllZeroCharAfterIdx(size_t idx)
{
    while (this->getInput()[++idx] == '0')
        ;
    if (this->getInput().length() == idx)
        return (true);
    return (false);
}