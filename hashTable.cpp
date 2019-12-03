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
    for(int i = 0; (i < word.size()); i++){
        key += (word.at(word.size()-i-1)-'a'+1)*exp(31,i);
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
int getFileIndex(vector <string> _files, string _fileName){
    for(int i = 0; i < _files.size(); i++){
        if(_files.at(i) == _fileName){
            return i;
        }
    }
    return -1;
}
void hashTable::checkCollisions(vector<string> _files, int plagiarismThreshold) { //files is the vector of fileNames from milestone I
    vector < vector <int> > collisionTable(_files.size(),vector<int> (_files.size(),0));//initialize the vector with 0's for all values
    //populate table with number of collisions stored based on indexes into _files
    for(int i = 0; i < tableSize;i++){
        if(myTable[i]!=NULL && myTable[i]->next != NULL){
            for(ListNode * ptr = myTable[i]; ptr != NULL; ptr = ptr->next){
                int j = getFileIndex(_files,ptr->fileName);
                for(ListNode * ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next){
                    int k = getFileIndex(_files,ptr2->fileName);
                    collisionTable[k][j]++;
                }
            }
        }
    }
    cheaters * head = NULL;
    for(int i = 2; i < _files.size(); i++){
        for(int j = i; j < _files.size(); j++){
            if(collisionTable[i][j]>plagiarismThreshold){
                cheaters * temp = new cheaters;
                temp->file1 = _files.at(i);
                temp->file2 = _files.at(j);
                temp->similarities = collisionTable[i][j];
                if(head == NULL){
                    head = temp;
                    temp->next = NULL;
                }
                else if(head->similarities < temp->similarities){
                    temp->next = head;
                    head = temp;
                }
                else{
                    bool found = false;
                    for(cheaters * ptr = head; ptr != NULL && !found; ptr = ptr->next){
                        if(ptr->next == NULL){
                            ptr->next = temp;
                            temp ->next = NULL;
                            found = true;
                        }
                        else if((ptr->next)->similarities < temp->similarities){
                            found = true;
                            temp->next = ptr->next;
                            ptr->next = temp;
                        }

                    }
                }
            }
        }
    }
    for(cheaters * ptr = head; ptr != NULL;){
        cheaters * temp = ptr;
        ptr = ptr->next;
        cout << temp->file1 << ":" << temp->file2 << " " << temp->similarities << endl;
        delete temp;
    }
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
