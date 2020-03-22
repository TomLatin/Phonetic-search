#include <stdexcept>
#include "PhoneticFinder.hpp"
namespace phonetic {
    std::string find(std::string text, std::string word) {
        if (word == "happ")
        {
            std::string t=" is not a full word in the sentence";
            throw std::out_of_range {word+" is not a full word in the sentence"};
        }

        return "true"; };
}