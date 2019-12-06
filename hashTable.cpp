//
// Created by Jeffrey and Darren on 11/25/2019.
//
#include "hashTable.h"
#include "math.h"

//the entire table needs to be initialized to NULL 
//so that the program knows when there is the first occurence of a key and so the end of the linked list can be found.
hashTable::hashTable() {
    for(int i = 0; i < tableSize; i++){
        myTable[i] = NULL;
    }
}
//this is a helper function since the pow() function was giving us problems even though it performs the same task
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
        key += (word.at(word.size()-i-1)-'a'+1)*exp(31,i);//this is the function conceptually covered in lecture as Method 3
	//the benefit is that every letter is included in the calculation and proves very accurate for generating separate keys
    }
    key = key%tableSize;   
    //if this is the first time this file's name is appearing in this list, insert the listnode
    if((myTable[key] == NULL) || (_fileName != (myTable[key]->fileName))){
        ListNode* temp= new ListNode;
        temp->fileName = _fileName;
        temp->next = myTable[key];
        myTable[key] = temp;
    }
}
//this is a helper function since we decided to store the file names and not their indices. 
//it takes in a file name that is in the files vector and returns it's index into said vector. 
//if the file is not in the vector, then -1 is returned to indicate that an error has occured
int getFileIndex(vector <string> _files, string _fileName){
    for(int i = 0; i < _files.size(); i++){
        if(_files.at(i) == _fileName){
            return i;
        }
    }
    return -1;
}
//This is the main part of the program as it created the 2D vector that shows the similarities between each combination of files
//and then prints to the screen those files whose similarities are greater than the plagiarism threshold. 
void hashTable::checkCollisions(vector<string> _files, int plagiarismThreshold) { //files is the vector of fileNames from milestone I
    vector < vector <int> > collisionTable(_files.size(),vector<int> (_files.size(),0));//initialize the vector with 0's for all values
    //populate table with number of collisions stored based on indexes into _files
    for(int i = 0; i < tableSize;i++){
        if(myTable[i]!=NULL && myTable[i]->next != NULL){
            for(ListNode * ptr = myTable[i]; ptr != NULL;){
                int j = getFileIndex(_files,ptr->fileName); //converts the file name stored in the LL into an index
                for(ListNode * ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next){
                    int k = getFileIndex(_files,ptr2->fileName); //converts the file names stored in the LL into an index
                    collisionTable[k][j]++;
                }
	        ListNode * temp = ptr;
	        ptr = ptr->next;
	        delete temp; //deallocate the memory as we go through the table so that we save time
            }
	    myTable[i]=NULL;//this prevents any accidental seg faults from trying to access a node that got deleted earlier
        }
	else if(myTable[i] != NULL){
	    delete myTable[i]; //this takes care of all of the keys with only one file name so that no memory is leaked
	    myTable[i] = NULL;
	}
    }
    cheaters * head = NULL; //we now create a linked list of the files considered plagiarized and then sort them as they are inserted
    for(int i = 2; i < _files.size(); i++){
        for(int j = i; j < _files.size(); j++){
            if(collisionTable[i][j]>plagiarismThreshold){
                cheaters * temp = new cheaters;
                temp->file1 = _files.at(i);
                temp->file2 = _files.at(j);
                temp->similarities = collisionTable[i][j];
                if(head == NULL){//conditional for the first node
                    head = temp;
                    temp->next = NULL;
                }
                else if(head->similarities < temp->similarities){ //condition for needing to insert at the top with a populated list
                    temp->next = head;
                    head = temp;
                }
                else{ //inserting in the middle where prev > current > next
                    bool found = false; //found used so that the list traversal stops when the node has been inserted
                    for(cheaters * ptr = head; ptr != NULL && !found; ptr = ptr->next){
                        if(ptr->next == NULL){ //checks for being at the end of the list and still not being added
                            ptr->next = temp; //adds the node to the end and makes this node the new end
                            temp ->next = NULL;
                            found = true;
                        }
                        else if((ptr->next)->similarities < temp->similarities){ //condition for inserting at the middle
                            found = true;
                            temp->next = ptr->next;
                            ptr->next = temp;
                        }

                    }
                }
            }
        }
    }
    for(cheaters * ptr = head; ptr != NULL;){ //given the sorted list, we can now print out the list and deallocate the memory as we go
        cheaters * temp = ptr;
        ptr = ptr->next;
        cout << temp->similarities << ": " << temp->file1 << ", " << temp->file2   << endl;
        delete temp;
    }
}
hashTable::~hashTable() {
    //delete all of the listNodes in the table so that there is no memory leaked
}
