#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

namespace phonetic {
    string find(string text, string word);
    bool cheakOneWord(string word);
    bool EqualWords(string wordFromText,string word);
}

