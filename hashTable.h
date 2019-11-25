//
// Created by Jeffrey on 11/25/2019.
//

#ifndef PROGRAM_8_HASHTABLE_H
#define PROGRAM_8_HASHTABLE_H
#include "chunk.h"
using namespace std;
struct ListNode{
    string fileName;
    ListNode * next;
};
class hashTable {
private:
    int tableSize;
    ListNode * myTable[5000];
public:
    hashTable();
    hashTable(int _size);
    void hash(string word,string fileName);
    vector<string> compare(string fileName);
    void showTable() const;
};
#endif //PROGRAM_8_HASHTABLE_H
