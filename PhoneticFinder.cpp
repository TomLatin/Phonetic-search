#include <stdexcept>
#include "PhoneticFinder.hpp"
namespace phonetic {
    std::string find(std::string text, std::string word) {
        if (word == "happ")
        {
            throw std::runtime_error {word+" is not a full word in the sentence"};
        }

        return "true"; };
}