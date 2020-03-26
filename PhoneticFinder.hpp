#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

namespace phonetic {
    string find(string text, string word);
}
bool cheakOneWord(string word);
bool EqualWords(string wordFromText,string word,int size);

