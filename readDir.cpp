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

int main()
{
    int chunkSize = 6;
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    for(unsigned int i = 2; i < 3;i++){//files.size();i++){
        cout << files[i] << endl;
        ifstream inFile;
        inFile.open("C:\\Users\\Jeffrey\\Dropbox\\College\\EE 312\\Program 8\\cmake-build-debug\\sm_doc_set\\abf0704.txt");//files[i]);
        vector <string> words;
        while(inFile){
            string temp;
            inFile >> temp;
            words.push_back(temp);
            if(words.size()==6){
                for(int i = 0; i < words.size();i++){
                    cout << words[i];
                }
                cout << endl;
                words.erase(words.begin());
            }
        }
        inFile.close();
    }
    return 0;
}
