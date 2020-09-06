/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

template <typename T>
MutantStack<T>::MutantStack()
    : std::stack<T>()
{
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

template <typename T>
MutantStack<T>::~MutantStack()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
    : std::stack<T>(other)
{
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
    std::cout << "Assign operator!" << std::endl;
    this->c = other.c;
    std::cout << this->c << std::endl;
    return (*this);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (this->c.rend());
}
