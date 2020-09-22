#ifndef SAMPLECLASS_HPP
# define SAMPLECLASS_HPP

# include <string>
# include <iostream>

class SampleClass
{
private:
    std::string _name;
public:
    SampleClass();
    SampleClass(const std::string& name);
    virtual ~SampleClass();
    SampleClass(const SampleClass& other);
    SampleClass& operator=(const SampleClass& other);

    const std::string& getName() const;

    std::string&        operator*();
    const std::string&  operator*() const;
    bool                operator!=(const SampleClass& other) const;
    bool                operator==(const SampleClass& other) const;
    bool                operator<(const SampleClass& other) const;
    bool                operator<=(const SampleClass& other) const;
    bool                operator>(const SampleClass& other) const;
    bool                operator>=(const SampleClass& other) const;
};

std::ostream&           operator<<(std::ostream& out, const SampleClass& other);

#endif