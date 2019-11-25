//
// Created by Jeffrey on 11/25/2019.
//
#include "hashTable.h"
#include "math.h"
hashTable::hashTable() {
    tableSize = 5000;
    for(int i = 0; i < tableSize; i++){
        myTable[i] = NULL;
    }
}
hashTable::hashTable(int _size) {
    tableSize = _size;
    for(int i = 0; i < tableSize; i++){
        myTable[i] = NULL;
    }
}
void hashTable::hash(string word,string _fileName) {
    int key = 0;
    for(int i = 0; i < word.size(); i++){
        key += word[word.size()-i-1]*pow(27.0,(double)(i%4));
    }
    key = key % tableSize;
    cout << key << endl;
    ListNode* temp= new ListNode;
    temp->fileName = _fileName;
    temp->next = myTable[key];
    myTable[key] = temp;
}
void hashTable::showTable() const {
    for (int i = 0; i < tableSize; i++){
        if(myTable[i]!=NULL){
            for(ListNode *ptr = myTable[i]; ptr != NULL; ptr = ptr->next){
                cout << ptr->fileName << " ";
            }
            cout << endl;
        }
    }
}
