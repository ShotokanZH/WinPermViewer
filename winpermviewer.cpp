#include <iostream>
#include <windows.h>
#include <strings.h>
#include <math.h>
using namespace std;

bool check(char *filename){
    int tmpatt = GetFileAttributes(filename),
        found = 0,
        max = 18;
    string attributes[] = {"READONLY","HIDDEN","SYSTEM","?","DIRECTORY","ARCHIVE","DEVICE","NORMAL","TEMPORARY","SPARSE_FILE","REPARSE_POINT","COMPRESSED","OFFLINE","NOT_CONTENT_INDEXED","ENCRYPTED","INTEGRITY_STREAM","VIRTUAL","NO_SCRUB_DATA"};
    
    for (int x = max-1; x>=0; x--){
        if(pow(2,x)<=tmpatt){
            cout<<attributes[x]<<"\n";
            tmpatt-=pow(2,x);
            found++;
        }
    }

    if (found){
        cout<<"\n"<<found<<" attribute(s) found for the file.\n";
        return 0;
    }

    cout<<"Not a regular file.\n";
    return 1;
}

int main(int argc, char **ARGV){
    if(argc==2)
        return check(ARGV[1]);
    cout<<"Usage:\n";
    cout<<ARGV[0]<<" [file|directory]\n";
    return 1;
}
