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
    
    /*
    *   Precondition: a hash table has been created
    *   Input: work chunk of length n, name of file chunk is from    
    *   Output: none
    *   Postcondition: word chunk has been hashed, and inputed into the hash table with the file index where it came from
    */
    void hash(string word,string fileName);
    
    /*
    *   Precondition:a hash table has been created
    *   Input: vector of file names to be read, threshold for plagerism
    *   Output: prints file names that are similar
    *   Postcondition: 
    *   
    *   Description: This is the main part of the program as it created the 2D vector that shows the similarities between each combination of files
    *   and then prints to the screen those files whose similarities are greater than the plagiarism threshold.  
    */
    void checkCollisions(vector <string> _files, int plagiarismThreshold);
    ~hashTable();
};
#endif //PROGRAM_8_HASHTABLE_H
