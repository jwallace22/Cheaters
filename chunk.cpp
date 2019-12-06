//
// Created by Jeffrey on 11/25/2019.
//
#include "chunk.h"
#include <string>
#include <algorithm>

using namespace std;
 //default constructor for a chunk. not necessary but added for initial testing of the class
chunk::chunk() {
    chunkSize = 4;
    myWords = "Error-not real chunk";
}
//this constructor takes in the _size number of words as a vector and combines them into a chunk (string)
//the size parameter is not necessary due to the .size() method of a vector but helps prevent an error if an extra word is in the vector somehow
chunk::chunk(int _size, vector<string> _words) {
    chunkSize = _size;
    myWords = filter(_words[0]); //each word is individually filtered before being added to the end of the string
    for(int i = 1; i < _words.size(); i++){
        myWords += filter(_words[i]); //since the vector is FIFO, we can add each element to the end of this string and they will be in order
    }
}
//this function is used to remove any punctuation or other non-letter characters from an individual word utilizing the erase and remove functions of a string
//this function does, however, allow for the unusual characters that appeared in some of these essays to stay since it targets what to remove instead of what to keep
string chunk::filter(string unfilteredWord) {
    string str = unfilteredWord;
    str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '?'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '.'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ','), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\''), str.end());
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ';'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '>'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '['), str.end());
    str.erase(std::remove(str.begin(), str.end(), ']'), str.end());
    for(int i = 0; i < str.size(); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}
