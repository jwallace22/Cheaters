//
// Created by Jeffrey on 11/25/2019.
//

#ifndef PROGRAM_8_HASHTABLE_H
#define PROGRAM_8_HASHTABLE_H
#include "chunk.h"
using namespace std;
//this is the list node that is used in the hashTable to store file names based on their chunks' keys from the hash function
struct ListNode{
    string fileName;
    ListNode * next;
};
//This is ussed as a linked list node specifically for printing out a sorted list of file combinations with more than a given number of similarities
struct cheaters{
    string file1;
    string file2;
    int similarities;
    cheaters * next;
};
class hashTable {
private:
    static const unsigned int tableSize = 499979;//large prime number chosen because bigger numbers caused valgrind errors
    ListNode * myTable[tableSize];//the hash table is a table of pointers to our linked lists
public:
    hashTable();
    void hash(string word,string fileName);
    void checkCollisions(vector <string> _files, int plagiarismThreshold);
    ~hashTable();
};
#endif //PROGRAM_8_HASHTABLE_H
