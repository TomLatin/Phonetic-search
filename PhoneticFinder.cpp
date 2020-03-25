#include "PhoneticFinder.hpp"
using namespace std

namespace phonetic {
    string find(string text, string word) {

        if(!cheakOneWord(word))
        {
            throw std::runtime_error {"The "+ word+" is invalid word"};
        }
        else
        {
            text+=" ";
            int index=0;
            string wordFromText="";
            for (int i = 0; i <text.size() ; ++i) {
                wordFromText="";
                index=0;
                while (text[i]!=' ')
                {
                    wordFromText[index]=text[i];
                    index++;
                }
                if(wordFromText.size()==word.size())
                {
                    if(EqualWords(wordFromText,word))
                    {
                        return wordFromText;
                    }
                }
            }

            throw std::runtime_error {word+" is not a full word in the sentence"};
        }

        bool cheakOneWord(string word)
        {

        }

        bool EqualWords(string wordFromText,string word)
        {

        }

    }
}