#include <iostream>
#include <fstream>
#include "mainFunction.h"
#include "Levenshtein.h"
using namespace std;

int SingalCorrector::findmin(){
    int min = distanceList[0];
    for(int i=0; i<distanceList.size();i++){
        if (distanceList[i]<min){
            min = distanceList[i];
        }
    }
    return min;
}

void SingalCorrector::output(int min){
    for(int i=0;i<vocabularyList.size();i++){
        if(distanceList[i] == min){
            cout<<vocabularyList[i]<<endl;
        }
    }
}


SingalCorrector::SingalCorrector(char* word):sourceWord(word),vocabularyList(),distanceList(){
}

void SingalCorrector::start(){
    ifstream dictFile(VOCABULARY_FILE);
    if(dictFile){
        string referenceWord;
        while(dictFile>>referenceWord){
            vocabularyList.push_back(referenceWord);
            Levenshtein pair(sourceWord,referenceWord);
            int distance = pair.calculate();
            if(distance == 0){
                cout<<"The word is correct."<<endl;
                return;
            }
            else{
                distanceList.push_back(distance);
            }
        }
        cout<<"Below are the similar words you may be want:";
        output(findmin());
        dictFile.close();
    }
    else{
        cout<<"Vocabulary file open error!"<<endl;
    }
}

FileCorrector::FileCorrector(char* name):fileName(name),vocabularyList(){
}

void FileCorrector::start(){//准备在错误词旁边用括号输出，并在屏幕输出，考虑用继承还是重写，继承是否要重写start方法
    cout<<"File check"<<endl;
} 


void giveHelp(){
    cout<<"Usage: wordsCorrector [options] [filename/signal word]"<<endl;
    cout<<"options:"<<endl;
    cout<<"\t-s single word\t Check for a singal word."<<endl;
    cout<<"\t-f filename\t Check for a whole txt file and output a new file in the same floder."<<endl;
    cout<<"\t--help\t\t Display this help information."<<endl;
}