#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& numbers) {
    std::vector<int> extractedNumbers = extractNumbers(numbers);
    checkForNegatives(extractedNumbers);
    return calculateSum(extractedNumbers);
}

std::vector<int> StringCalculator::extractNumbers(const std::string& numbers) {
    return convertToIntegers(split(numbers, ",\n"));
}

std::vector<std::string> StringCalculator::split(const std::string& text, const std::string& delimiters) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find_first_of(delimiters, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

std::vector<int> StringCalculator::convertToIntegers(const std::vector<std::string>& strings) {
    std::vector<int> numbers;
    for (const std::string& str : strings) {
        numbers.push_back(std::stoi(str));
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
    std::string message = "Negatives not allowed: ";
    for (int negative : negatives) {
        message += std::to_string(negative) + " ";
    }
    return message;
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}

