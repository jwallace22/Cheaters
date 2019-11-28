//
// Created by Jeffrey on 11/25/2019.
//

#ifndef PROGRAM_8_HASHTABLE_H
#define PROGRAM_8_HASHTABLE_H
#include "chunk.h"
using namespace std;
struct ListNode{
    string fileName;
    string value;
    ListNode * next;
};
class hashTable {
private:
    static const unsigned int tableSize = 499979;
    ListNode * myTable[tableSize];
public:
    hashTable();
    void hash(string word,string fileName);
    void showTable() const;
    void checkCollisions(vector <string> _files, int plagiarismThreshold);
    ~hashTable();
};
#endif //PROGRAM_8_HASHTABLE_H
