#include "Convert.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

Convert::Convert(std::string input)
: _input(input)
{
    for (int i = TYPE_CHAR; i < TYPE_DOUBLE; i++)
        this->_flags[i] = NORMAL_FLAG;
<<<<<<< HEAD
    this->_science[0] = "inf";
    this->_science[1] = "nan";
    this->_science[2] = "inff";
    this->_science[3] = "nanf";
=======
	this->_science[0] = "inf";
	this->_science[1] = "nan";
	this->_science[2] = "inff";
	this->_science[3] = "nanf";
>>>>>>> b24310a3f45a7570108e15b49215822dfd4cf287
    this->_type = detectLiteralType();
    parsingLiteralType();
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

Convert::~Convert()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

Convert::Convert(const Convert& other)
: _input(other.getInput())
{
<<<<<<< HEAD
    this->_science[0] = "inf";
    this->_science[1] = "nan";
    this->_science[2] = "inff";
    this->_science[3] = "nanf";
=======
	this->_science[0] = "inf";
	this->_science[1] = "nan";
	this->_science[2] = "inff";
	this->_science[3] = "nanf";
>>>>>>> b24310a3f45a7570108e15b49215822dfd4cf287
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

Convert& Convert::operator=(const Convert& other)
{
    this->_input = other.getInput();
    this->_type = other.getInputType();
	this->_science[0] = "inf";
	this->_science[1] = "nan";
	this->_science[2] = "inff";
	this->_science[3] = "nanf";
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
/*################    Member functions    ##################*/
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
    parseToCharValue();
    parseToIntValue();
    parseToFloatValue();
    parseToDoubleValue();
    set_flag_if_inf_or_nan();
    (void)type;
}

void Convert::parseToCharValue()
{
    std::stringstream ss;
    int ivalue;

    if (this->getInput().length() == 3 && this->getInput()[0] == '\'' && this->getInput()[2] == '\'')
        this->_cvalue = this->getInput()[1];
    else
    {
        ivalue = this->getInput()[0];
        if (ivalue > 127 || ivalue < 0)
            this->_flags[TYPE_CHAR] = OVERFLOW_FLAG;
        this->_cvalue = static_cast<char>(ivalue);
    }
}

void Convert::parseToIntValue()
{
    std::stringstream ss;
    long long llvalue;

    ss << this->getInput();
    ss >> llvalue;
    if (llvalue > std::numeric_limits<int>::max() || llvalue < std::numeric_limits<int>::min())
        this->_flags[TYPE_INT] = OVERFLOW_FLAG;
    this->_ivalue = static_cast<int>(llvalue);
}

void Convert::parseToFloatValue()
{
    std::stringstream ss;
    double dvalue;

    if (this->getInputType() == TYPE_CHAR)
        dvalue = static_cast<double>(static_cast<int>(this->getCharValue()));
    else
        dvalue =  strtod(this->getInput().c_str(), NULL);
    if (dvalue > std::numeric_limits<float>::max() || dvalue < std::numeric_limits<float>::lowest())
        this->_flags[TYPE_FLOAT] = OVERFLOW_FLAG;
    this->_fvalue = static_cast<float>(dvalue);
}

void Convert::parseToDoubleValue()
{
    std::stringstream ss;
    long double ldvalue;

    ss << this->getInput();
    ss >> ldvalue;
    if (ldvalue > std::numeric_limits<double>::max() 
        || ldvalue < std::numeric_limits<double>::lowest())
        this->_flags[TYPE_DOUBLE] = OVERFLOW_FLAG;
    this->_dvalue = static_cast<double>(ldvalue);
}

void Convert::set_flag_if_inf_or_nan()
{
    std::string tmp = this->getInput();
    if (tmp[0] == '+' || tmp[0] == '-')
        tmp = tmp.substr(1);
    for (int i = 0; i < 4; i++)
    {
        if (!tmp.compare(_science[i]) && i % 2 == 0)
        {
            this->_flags[TYPE_FLOAT] = INF_FLAG;
            this->_flags[TYPE_DOUBLE] = INF_FLAG;
        }
        else if (!tmp.compare(_science[i]) && i % 2 == 1)
        {
            this->_flags[TYPE_FLOAT] = NAN_FLAG;
            this->_flags[TYPE_DOUBLE] = NAN_FLAG;
        }
    }
}

bool Convert::isCharInput() const
{
    std::string tmp; 
    
    tmp = this->getInput();
    if (tmp.length() == 1 && !isdigit(tmp[0]))
        return (true);
    if (tmp.length() == 3 && tmp[0] == '\'' && tmp[2] == '\'')
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

bool Convert::isOverflow(int type, char case_flag) const
{
    (void)case_flag;
    if (this->_flags[type] == OVERFLOW_FLAG)
        return (true);
    if (type == TYPE_INT &&
        (this->getIntValue() > 127 || this->getIntValue() < 0))
        return (true);
    if (type == TYPE_FLOAT &&
        (this->getFloatValue() > 127 || this->getFloatValue() < 0))
        return (true);
    if (type == TYPE_DOUBLE &&
        (this->getDoubleValue() > 127 || 0))
        return (true);
    return (false);
}

bool Convert::isOverflow(int type, int case_flag) const
{
    (void)case_flag;
    if (this->_flags[type] == OVERFLOW_FLAG)
        return (true);
    if (type == TYPE_FLOAT &&
        (this->getFloatValue() > static_cast<float>(std::numeric_limits<int>::max()) || this->getFloatValue() < static_cast<float>(std::numeric_limits<int>::lowest())))
        return (true);
    if (type == TYPE_DOUBLE &&
        (this->getDoubleValue() > std::numeric_limits<int>::max() || this->getDoubleValue() < std::numeric_limits<int>::lowest()))
        return (true);
    return (false);
}

bool Convert::isOverflow(int type, float case_flag) const
{
    (void)case_flag;
    if (this->_flags[type] == OVERFLOW_FLAG)
        return (true);
    if (type == TYPE_DOUBLE &&
        (this->getDoubleValue() > std::numeric_limits<float>::max() || this->getDoubleValue() < std::numeric_limits<float>::lowest()))
        return (true);
    return (false);
}

bool Convert::isOverflow(int type, double case_flag) const
{
    (void)case_flag;
    if (this->_flags[type] == OVERFLOW_FLAG)
        return (true);
    if (this->_flags[TYPE_DOUBLE] == OVERFLOW_FLAG)
        return (true);
    return (false);
}

char Convert::getValueAsChar()
{
    char ret;

    ret = '\0';
    int type = this->getInputType();
    if (type == TYPE_INVALID || isOverflow(type, ret))
        throw Convert::ImpossibleException();
    if (type == TYPE_CHAR)
        ret = getCharValue();
    else if (type == TYPE_INT)
        ret = static_cast<char>(this->getIntValue());
    else if (type == TYPE_FLOAT)
        ret = static_cast<char>(this->getFloatValue());
    else if (type == TYPE_DOUBLE)
        ret = static_cast<char>(this->getDoubleValue());
    if (!isprint(ret))
        throw Convert::NonDisplayableException();
    return (ret);
}


int Convert::getValueAsInt()
{
    int ret;

    ret = 0;
    int type = this->getInputType();
    if (type == TYPE_INVALID || isOverflow(type, ret))
        throw Convert::ImpossibleException();
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
    if (type == TYPE_INVALID && (this->_flags[TYPE_FLOAT] == INF_FLAG || this->_flags[TYPE_FLOAT] == NAN_FLAG))
        throwInfOrNan();
    else if (type == TYPE_INVALID || isOverflow(type, ret))
        throw Convert::ImpossibleException();
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

float Convert::getValueAsDouble()
{
    double ret;

    ret = 0.0;
    int type = this->getInputType();
    if (type == TYPE_INVALID && (this->_flags[TYPE_DOUBLE] == INF_FLAG || this->_flags[TYPE_DOUBLE] == NAN_FLAG))
        throwInfOrNan();
    else if (type == TYPE_INVALID || isOverflow(type, ret))
        throw Convert::ImpossibleException();
    else if (type == TYPE_CHAR)
        ret = static_cast<double>(static_cast<int>(this->getCharValue()));
    else if (type == TYPE_INT)
        ret = static_cast<double>(this->getIntValue());
    else if (type == TYPE_FLOAT)
        ret = static_cast<double>(this->getFloatValue());
    else if (type == TYPE_DOUBLE)
        ret = this->getDoubleValue();
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
        std::cout<<ret<<"'"<<char_value<<"'"<<std::endl;
    }
    catch(const std::exception& e)
    {
        ret += e.what();
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
    catch(const std::exception& e)
    {
        ret += e.what();
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
    catch(const Convert::InfException& e)
    {
        if (this->getInput()[0] == '-')
            ret += this->getInput()[0];
        ret += e.what();
        ret += "f";
        std::cout<<ret<<std::endl;
    }
    catch(const Convert::NanException& e)
    {
        if (this->getInput()[0] == '-')
            ret += this->getInput()[0];
        ret += e.what();
        ret += "f";
        std::cout<<ret<<std::endl;
    }
    catch(const std::exception& e)
    {
        ret += e.what();
        std::cout<<ret<<std::endl;
    }
}

void Convert::toDoubleAndPrint()
{
    std::string ret;
    double double_value;

    ret = "double: ";
    try
    {
        double_value = this->getValueAsDouble();
        size_t idx = this->getInput().find('.');
        std::string suffix = "";
        
        if (idx == std::string::npos || isAllZeroCharAfterIdx(idx))
            suffix = ".0";
        std::cout<<ret<<double_value<<suffix<<std::endl;
    }
    catch(const Convert::InfException& e)
    {
        if (this->getInput()[0] == '-')
            ret += this->getInput()[0];
        ret += e.what();
        std::cout<<ret<<std::endl;
    }
    catch(const Convert::NanException& e)
    {
        if (this->getInput()[0] == '-')
            ret += this->getInput()[0];
        ret += e.what();
        std::cout<<ret<<std::endl;
    }
    catch(const std::exception& e)
    {
        ret += e.what();
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

void Convert::throwInfOrNan()
{
    int flag = this->_flags[TYPE_FLOAT];

    if (flag == INF_FLAG)
        throw Convert::InfException();
    else if (flag == NAN_FLAG)
        throw Convert::NanException();
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char* Convert::ImpossibleException::what() const throw ()
{
    return "impossible";
}

const char* Convert::InfException::what() const throw ()
{
    return "inf";
}

const char* Convert::NanException::what() const throw ()
{
    return "nan";
}

const char* Convert::NonDisplayableException::what() const throw ()
{
    return "Non displayable";
}
