

#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = ",\n";
    std::string nums = extractNumbers(numbers, delimiters);

    std::vector<std::string> tokens = split(nums, delimiters);
    std::vector<int> integers = convertToIntegers(tokens);
    checkForNegatives(integers);

    return calculateSum(integers);
}

std::string StringCalculator::extractNumbers(const std::string& numbers, std::string& delimiters) {
    if (numbers.find("//") == 0) {
        size_t delimiter_end = numbers.find("\n");
        delimiters = numbers.substr(2, delimiter_end - 2);
        return numbers.substr(delimiter_end + 1);
    }
    return numbers;
}

std::vector<std::string> StringCalculator::split(const std::string& str, const std::string& delimiters) {
    std::vector<std::string> tokens;
    std::regex re("[" + delimiters + "]");
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator end;
    for (; it != end; ++it) {
        tokens.push_back(*it);
    }
    return tokens;
}

std::vector<int> StringCalculator::convertToIntegers(const std::vector<std::string>& tokens) {
    std::vector<int> integers;
    for (const std::string& token : tokens) {
        if (!token.empty()) {
            integers.push_back(std::stoi(token));
        }
    }
    return integers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives = findNegatives(numbers);
    throwIfNegativesExist(negatives);
}

std::vector<int> StringCalculator::findNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }
    return negatives;
}

void StringCalculator::throwIfNegativesExist(const std::vector<int>& negatives) {
    if (!negatives.empty()) {
        std::string message = "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            message += std::to_string(negatives[i]);
            if (i != negatives.size() - 1) {
                message += ", ";
            }
        }
        throw std::runtime_error(message);
    }
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num <= 1000) {
            sum += num;
        }
    }
    return sum;
}
