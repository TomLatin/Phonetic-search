#include "PhoneticFinder.hpp"

string phonetic::find(string text, string word) {

    //check if the word is legal i.e there is not space in the word like "a t" or it empty string i.e "" .
    if(word=="")
    {
        throw std::runtime_error {"The "+ word+" is invalid word"};
    }
    else //it is a legal word
    {
        text+=" ";
        string wordFromText="";
        for (int i = 0; i <text.size()+1 ; i++) {
            if (text[i] != ' ') wordFromText += text[i];

            else{
                if (wordFromText.size() == word.size()) //Checking if the length of the words is equal Because if the length is different, it's not the same word
                {
                    if (EqualWords(wordFromText, word, wordFromText.size()))
                    {
                        return wordFromText;
                    }
                }
                wordFromText.clear();//Resets the string after checking the word in the text and find that she isn't the one
            }
        }
        throw std::runtime_error {word+" is not a full word in the sentence"};
    }
}

bool cheakOneWord(string word)
{
    return true;
}

/*
   can mix in the letters:
    v, w
    b, f, p
    g, j
    c, k, q
    s, z
    d, t
    o, u
    i, y

    and also can mix in big letter to little letter
 */
bool EqualWords(string wordFromText,string wordOriginal,int size)
{

    string wordFromTextTemp=toLowewCase(wordFromText);
    string word=toLowewCase(wordOriginal);
    for (int i = 0; i <size ; ++i)
    {
        if(wordFromTextTemp[i]==word[i]) continue;
        else if((wordFromTextTemp[i]==word[i]+('a'-'A')) || (wordFromTextTemp[i]+('a'-'A')==word[i]) )  continue;
        else if((wordFromTextTemp[i]=='v' && word[i]=='w') || (wordFromTextTemp[i]=='w' && word[i]=='v'))  continue;
        else if((wordFromTextTemp[i]=='b' && ((word[i]=='f')||(word[i]=='p')) )|| (wordFromTextTemp[i]=='f' && ((word[i]=='b' || word[i]=='p' ))) || (wordFromTextTemp[i]=='p' && ((word[i]=='b' || word[i]=='f' ) )))   continue;
        else if((wordFromTextTemp[i]=='g' && word[i]=='j' )||( wordFromTextTemp[i]=='j' && word[i]=='g'  ))  continue;
        else if((wordFromTextTemp[i]=='c' && (word[i]=='k'||word[i]=='q') )||( wordFromTextTemp[i]=='k' && (word[i]=='c' || word[i]=='q' )) ||(wordFromTextTemp[i]=='q' && (word[i]=='c' || word[i]=='k' ))  )  continue;
        else if((wordFromTextTemp[i]=='s' && word[i]=='z') || (wordFromTextTemp[i]=='z' && word[i]=='s')  )  continue;
        else if((wordFromTextTemp[i]=='d' && word[i]=='t') || (wordFromTextTemp[i]=='t' && word[i]=='d')  )  continue;
        else if((wordFromTextTemp[i]=='o' && word[i]=='u') || (wordFromTextTemp[i]=='u' && word[i]=='o')  )  continue;
        else if((wordFromTextTemp[i]=='i' && word[i]=='y') || (wordFromTextTemp[i]=='y' && word[i]=='i') )  continue;
        else return false;
    }
    return true;
}

string toLowewCase(string word)
{
    string temp="";
    for (int i = 0; i <word.size() ; ++i) {
        if(word[i]>='A' && word[i]<='Z')
        {
            temp+=tolower(word[i]);
        }
        else
        {
            temp+=word[i];
        }
    }

    return temp;
}

