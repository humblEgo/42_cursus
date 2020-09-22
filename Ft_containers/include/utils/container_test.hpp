#ifndef CONTAINER_TEST_HPP
# define CONTAINER_TEST_HPP

# include <iostream>
# include <iomanip>

void printTest(std::string test_name);
void printResult(bool result);
void printCase(std::string case_text);
bool checkResultManually(void);

void vectorTest();
void listTest();
// void stackTest();

#endif