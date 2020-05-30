#include <iostream>
#include <cstring>
#include "mainFunction.h"
using namespace std;

int main(int argc, char* argv[]){
    //two shell command argument
    if(argc > 3){
        cout<<"More arguments than needed!"<<endl;
        giveHelp();
        return 1;
    }
    else if(argc == 1){
        cout<<"Welcome to words corrector!"<<endl;
        giveHelp();
        return 0;
    }
    else if(argc == 2){
        if(strcmp(argv[1], "--help") == 0){
            giveHelp();
            return 0;
        }
        else{
            cout<<"Need more arguments!"<<endl;
        }
    }
    else if(argc == 3){
         if(strcmp(argv[1], "-s") == 0){// check single word
            char* word = argv[2];
            SingalCorrector p(word);
            p.start();
            return 0;
        }
        else if(strcmp(argv[1], "-f") == 0){// check a file
            char* filename = argv[2];
            FileCorrector p(filename);
            p.start();
            return 0;
        }
        else{
            cout<<"Argument not finded"<<endl;
            giveHelp();
            return 1;
        }
    }
    return 0;
}