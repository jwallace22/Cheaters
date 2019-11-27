//
// Created by Jeffrey on 11/25/2019.
//
#include "chunk.h"
#include <string>
#include <algorithm>

using namespace std;

chunk::chunk() {
    chunkSize = 4;
    myWords = "Error-not real chunk";
}
chunk::chunk(int _size, vector<string> _words) {
    chunkSize = _size;
    myWords = filter(_words[0]);
    for(int i = 1; i < _words.size(); i++){
        myWords += filter(_words[i]);
    }
}
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