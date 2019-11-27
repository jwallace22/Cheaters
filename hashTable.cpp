//
// Created by Jeffrey on 11/25/2019.
//
#include "hashTable.h"
#include "math.h"
hashTable::hashTable() {
    for(int i = 0; i < tableSize; i++){
        myTable[i] = NULL;
    }
}
unsigned int exp(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    unsigned int result = base;
    for(int i = 1; i < exponent; i++){
        result *= base;
    }
    return result;
}
void hashTable::hash(string word,string _fileName) {
    unsigned int key = 0;
    // calculate the key based on the string using the method learned in class
    int length = word.size();
    if(length > 25){
        length = 25;
        length = word.size();
    }
    for(int i = 0; (i < length); i++){
        key += (word.at(i)-'a'+1)*exp(11,i);
    }
    key = key%tableSize;
    bool match = false;
    //check to see if the file is already in this key's linked list. ie. the file used the chunk more than once.
    for(ListNode * ptr = myTable[key]; ptr != NULL; ptr = ptr->next){
        if(ptr->fileName==_fileName){
            match = true;
        }
    }
    //if this is the first time this file's name is appearing in this list, insert the listnode
    if(!match){
        ListNode* temp= new ListNode;
        temp->fileName = _fileName;
        temp->value = word;
        temp->next = myTable[key];
        myTable[key] = temp;
    }
}
void hashTable::showTable() const {
    ofstream outputFile;
    outputFile.open("outputTest.txt");
    int numErrors = 0;
    int numKeys = 0;
    for (int i = 0; i < tableSize; i++){
        if(myTable[i]!=NULL && myTable[i]->next != NULL){ // only show potentially plagiarized chunks and their source files.
            outputFile << i << " ";
            numKeys++;
            string previous = myTable[i]->value;
            for (ListNode *ptr = myTable[i]; ptr != NULL; ptr = ptr->next) {
                if(ptr->value != previous){
                    numErrors++;
                }
                outputFile << ptr->value << " ";
            }
            outputFile << endl;
        }
    }
    outputFile.close();
    //this is a debugging statement used to find the number of times a key has multiple (unidentical) chunks that result in this key.
    cout << "Number of Collisions Found: " << numErrors << " Out of "<< numKeys << " keys with multiple values" << endl;
}
hashTable::~hashTable() {
    //delete all of the listNodes in the table so that there is no memory leaked
    for(int i = 0; i < tableSize; i++){
        if(myTable[i]!=NULL){
            for(ListNode*ptr = myTable[i]; ptr != NULL;){
                ListNode * temp = ptr;
                ptr = ptr->next;
                delete(temp);
            }
        }
    }
}
