#include "PhoneticFinder.hpp"

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
    Each number in the array represents a set of letters that can be exchanged.
    index 0 represents the letter a index 1 represents the lettergit add b שnd so on
 */
int arrABC[]={1,2,3,4,5,2,6,7,8,6,3,9,10,11,12,2,3,13,14,4,12,15,15,16,8,14};

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


bool EqualWords(string wordFromText,string wordOriginal,int size)
{
    for (int i = 0; i <size ; ++i)
    {
        if(!EqualChar(wordFromText[i],wordOriginal[i]))
        {
            return false;
        }
    }
    return true;
}

bool EqualChar(char chFromText,char chOriginal )
{
    int index1,index2;

    if(chFromText>='a'&&chFromText<='z')
    {
        index1=chFromText-'a';
    }
    else
    {
        index1=chFromText-'A';
    }

    if(chOriginal>='a'&&chOriginal<='z')
    {
        index2=chOriginal-'a';
    }
    else
    {
        index2=chOriginal-'A';
    }

    if(arrABC[index1]==arrABC[index2])
    {
        return true;
    }
    else
    {
        return false;
    }
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

