#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "chunk.h"
#include "hashTable.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}
int scanFiles (vector<string> _files, int _chunkSize, int plagiarismThreshold, string dir){
    hashTable table;
    for(unsigned int i = 2; i < _files.size();i++){
        ifstream inFile;
        inFile.open((dir+"/"+_files[i]).c_str(),inFile.in);
        vector <string> words;
        while(inFile){
            string temp;
            inFile >> temp;
            words.push_back(temp);
            if(words.size()==_chunkSize){
                chunk temp = chunk(_chunkSize,words);
                table.hash(temp.getString(),_files[i]);
                words.erase(words.begin());
            }
        }
        inFile.close();
    }
    table.showTable();
    table.checkCollisions(_files, plagiarismThreshold);
    return 0;
}
int main(int argc, char ** argv)
{
    int plagiarismThreshold = stoi(argv[3]);
    int chunkSize = stoi(argv[2]);
    string dir = argv[1];
    vector<string> files = vector<string>();
    getdir(dir,files);
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    cout << endl;
    return scanFiles(files, chunkSize, plagiarismThreshold,dir);
}