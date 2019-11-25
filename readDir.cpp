#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>

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
int printChunks (vector<string> _files, int _chunkSize){
    ofstream outputFile;
    outputFile.open("outputTest.txt");
    for(unsigned int i = 2; i < _files.size();i++){//files.size();i++){

        cout << _files[i] << endl;
        outputFile << _files[i] << endl;
        ifstream inFile;
        inFile.open(_files[i]);//files[i]);
        vector <string> words;

        while(inFile){
            string temp;
            inFile >> temp;
            words.push_back(temp);
            if(words.size()==_chunkSize){
                for(int i = 0; i < words.size();i++){
                    outputFile << words[i];
                }
                outputFile << endl;
                words.erase(words.begin());
            }
        }
        inFile.close();
        outputFile << endl;
    }
    outputFile.close();
    return 0;
}
int main()
{
    int chunkSize = 6;
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    cout << endl;

    printChunks(files, chunkSize);
    return 0;
}
