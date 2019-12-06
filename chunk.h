//
// Created by Jeffrey on 11/25/2019.
//

#ifndef PROGRAM_8_CHUNK_H
#define PROGRAM_8_CHUNK_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
class chunk {
private:
    string myWords;
    int chunkSize;
public:
    chunk();
    chunk(int _size, vector<string> _words);
    string filter(string unfilteredWord);
    //getString or toString are common methods to include in a class as to return a string representation of said class.
    //in this case the main part of the chunk is the string which makes this function quite trivial
    string getString() const{
        return myWords;
    }
};
#endif //PROGRAM_8_CHUNK_H
