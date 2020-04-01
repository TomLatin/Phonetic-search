#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

namespace phonetic {
    string find(string text, string word);
}
//private function
bool EqualWords(string wordFromText,string word,int size);
bool EqualChar(char chFromText,char chOriginal );
string toLowewCase(string word);

