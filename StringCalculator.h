#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string extractNumbers(const std::string& numbers, std::string& delimiters);
    std::vector<std::string> split(const std::string& str, const std::string& delimiters);
    std::vector<int> convertToIntegers(const std::vector<std::string>& tokens);
    void checkForNegatives(const std::vector<int>& numbers);
    std::vector<int> findNegatives(const std::vector<int>& numbers);
    void throwIfNegativesExist(const std::vector<int>& negatives);
    int calculateSum(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H


