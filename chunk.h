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
    string getString() const{
        return myWords;
    }
};
#endif //PROGRAM_8_CHUNK_H
