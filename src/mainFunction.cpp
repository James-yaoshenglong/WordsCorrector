#include <iostream>
#include "mainFunction.h"
using namespace std;

SingalCorrector::SingalCorrector(char* word):sourceWord(word){
}

void SingalCorrector::start(){
    cout<<"single words check"<<endl;
}

FileCorrector::FileCorrector(char* name):fileName(name){
}

void FileCorrector::start(){
    cout<<"File check"<<endl;
} 


void giveHelp(){
    cout<<"Usage: wordsCorrector [options] [filename/signal word]"<<endl;
    cout<<"options:"<<endl;
    cout<<"\t-s single word\t Check for a singal word."<<endl;
    cout<<"\t-f filename\t Check for a whole txt file and output a new file in the same floder."<<endl;
    cout<<"\t--help\t\t Display this help information."<<endl;
}