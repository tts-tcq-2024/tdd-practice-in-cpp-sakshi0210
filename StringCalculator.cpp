#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) return 0;
    
    std::vector<int> extractedNumbers = extractNumbers(numbers);
    checkForNegatives(extractedNumbers);
    return calculateSum(extractedNumbers);
}

std::vector<int> StringCalculator::extractNumbers(const std::string& numbers) {
    std::string delimiters = ",\n";
    std::string numbersToParse = numbers;

    if (numbersToParse.substr(0, 2) == "//") {
        size_t delimiterEnd = numbersToParse.find('\n');
        delimiters += numbersToParse.substr(2, delimiterEnd - 2);
        numbersToParse = numbersToParse.substr(delimiterEnd + 1);
    }

    return convertToIntegers(split(numbersToParse, delimiters));
}

std::vector<std::string> StringCalculator::split(const std::string& text, const std::string& delimiters) {
    std::vector<std::string> tokens;
    std::regex re("[" + delimiters + "]");
    std::sregex_token_iterator it(text.begin(), text.end(), re, -1);
    std::sregex_token_iterator end;
    for (; it != end; ++it) {
        tokens.push_back(*it);
    }
    return tokens;
}

std::vector<int> StringCalculator::convertToIntegers(const std::vector<std::string>& strings) {
    std::vector<int> numbers;
    for (const std::string& str : strings) {
        if (!str.empty()) {
            numbers.push_back(std::stoi(str));
        }
    }
    return numbers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives = findNegatives(numbers);
    if (!negatives.empty()) {
        throw std::runtime_error(buildNegativesErrorMessage(negatives));
    }
}

std::vector<int> StringCalculator::findNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }
    return negatives;
}

std::string StringCalculator::buildNegativesErrorMessage(const std::vector<int>& negatives) {
    std::ostringstream message;
    message << "Negatives not allowed: ";
    for (size_t i = 0; i < negatives.size(); ++i) {
        if (i > 0) {
            message << ", ";
        }
        message << negatives[i];
    }
    return message.str();
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

