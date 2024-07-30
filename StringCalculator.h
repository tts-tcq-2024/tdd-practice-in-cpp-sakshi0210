#include <vector>
#include <string>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);
    std::vector<int> extractNumbers(const std::string& numbers);
    std::vector<std::string> split(const std::string& text, const std::string& delimiters);
    std::vector<int> convertToIntegers(const std::vector<std::string>& strings);
    void checkForNegatives(const std::vector<int>& numbers);
    std::vector<int> findNegatives(const std::vector<int>& numbers);
    std::string buildNegativesErrorMessage(const std::vector<int>& negatives);
    int calculateSum(const std::vector<int>& numbers);
};

