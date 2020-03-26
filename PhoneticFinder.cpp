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
bool EqualWords(string wordFromText,string word,int size)
{
    for (int i = 0; i <size ; ++i)
    {
        if(wordFromText[i]==word[i]) continue;
        else if((wordFromText[i]==word[i]+('a'-'A')) || (wordFromText[i]==word[i]+('A'-'a')) )  continue;
        else if((wordFromText[i]=='v' && word[i]=='w') || (wordFromText[i]=='w' && word[i]=='v'))  continue;
        else if((wordFromText[i]=='b' && ((word[i]=='f')||(word[i]=='p')) )|| (wordFromText[i]=='f' && ((word[i]=='b' || word[i]=='p' ))) || (wordFromText[i]=='p' && ((word[i]=='b' || word[i]=='f' ) )))   continue;
        else if((wordFromText[i]=='g' && word[i]=='j' )||( wordFromText[i]=='j' && word[i]=='g'  ))  continue;
        else if((wordFromText[i]=='c' && (word[i]=='k'||word[i]=='q') )||( wordFromText[i]=='k' && (word[i]=='c' || word[i]=='q' )) ||(wordFromText[i]=='q' && (word[i]=='c' || word[i]=='k' ))  )  continue;
        else if((wordFromText[i]=='s' && word[i]=='z') || (wordFromText[i]=='z' && word[i]=='s')  )  continue;
        else if((wordFromText[i]=='d' && word[i]=='t') || (wordFromText[i]=='t' && word[i]=='d')  )  continue;
        else if((wordFromText[i]=='o' && word[i]=='u') || (wordFromText[i]=='u' && word[i]=='o')  )  continue;
        else if((wordFromText[i]=='i' && word[i]=='y') || (wordFromText[i]=='y' && word[i]=='i') )  continue;
        else return false;
    }
    return true;
}

