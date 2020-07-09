#include <iostream>
#include <fstream>
#include "mainFunction.h"
#include "Levenshtein.h"
using namespace std;

int findmin(vector<int> distanceList){
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
        cout<<"Below are the similar words you may be want:"<<endl;
        output(findmin(distanceList));
        dictFile.close();
    }
    else{
        cout<<"Vocabulary file open error!"<<endl;
    }
}

void FileCorrector::split(const string& source, string& word, string& punctuation){
    punctuation.clear();
    int i = source.length()-1;
    while(!( (source[i]>='A'&&source[i]<='Z') || (source[i]>='a'&&source[i]<='z') )){
        punctuation = source[i] + punctuation;
        i--;//这个不要忘，不然死循环
    }
    word = source.substr(0,i+1);
}

void FileCorrector::output(const string& word, const string& punctuation, ofstream& outFile,bool flag){
    if(flag){//此处添加原文行号位置
        cout<<"In line:"<<lineNum<<" "<<word<<" is wrong! Below are the similar words you may be want:"<<endl;
        int min = findmin(distanceList);
        outFile<<word<<"(";
        for(int i=0;i<distanceList.size();i++){//vocabulary 有可能比distancelist长
            if(distanceList[i] == min){
                cout<<vocabularyList[i]<<endl;
                outFile<<vocabularyList[i]<<" ";
            }
        }
        outFile<<")"<<punctuation;
    }
    else{
        outFile<<word<<punctuation;
    }
}

FileCorrector::FileCorrector(char* name):fileName(name),vocabularyList(),distanceList(),lineNum(1){
    //拆分文件扩展名,形成输出文件名
    int i;
    for(i=fileName.length()-1;i>=0;i--){//不能重复定义，不然scope会变
        if(fileName[i] == '.'){
            break;
        }
    }
    if(i>=0){//to make sure no out of range of the below two substr function
    outputName = fileName.substr(0,i)+"corrected"+fileName.substr(i,fileName.length()-i);//不能加括号，加了就会有'',这个bug还为解决
    }
    else{
        outputName = fileName+"corrected";
    }
}


void FileCorrector::start(){//不用继承，要重写太多方法，以后可以想方法整合
    // cout<<"File check"<<endl;
    ifstream dictFile(VOCABULARY_FILE);
    if(dictFile){
        //read in the vocabulary list
       string referenceWord;
        while(dictFile>>referenceWord){
            vocabularyList.push_back(referenceWord);
        }
        dictFile.close();
        //读取文件
        ifstream inFile(fileName);
        if(inFile){
            string sourceWord;
            ofstream outFile(outputName);
            if(outFile){
                while(inFile>>sourceWord){
                    //拆分单词和标点
                    string word,punctuation;
                    split(sourceWord,word,punctuation);
                    //重复上述单个单词检查方法
                    int flag = 0;
                    if(word.length() != 0){
                        flag = 1;
                        for(int i=0; i<vocabularyList.size();i++){
                            Levenshtein pair(word,vocabularyList[i]); //pay attention to copy
                            int distance = pair.calculate();
                            if(distance == 0){
                                flag = 0;
                                break;
                            }
                            else{
                                distanceList.push_back(distance);
                            }
                        }
                    }
                    //输出
                     output(word,punctuation,outFile,flag);
                    //输出空白符和清空distancelist
                    distanceList.clear();
                    char whiteChar = inFile.get();
                    if (whiteChar == '\n'){
                        lineNum++; //行号计数
                    }
                    outFile<<whiteChar;//need to use char to 强制类型转换
                }
                outFile.close();
            }
            else{
                cout<<"Output error!"<<endl;
            }
            inFile.close();
        }
        else{
            cout<<"Can not open the source file!"<<endl;
        }
    } 
    else{
        cout<<"Vocabulary file open error!"<<endl;
    }
} 


void giveHelp(){
    cout<<"Usage: ./wordsCorrector [options] [filename/signal word]"<<endl;
    cout<<"options:"<<endl;
    cout<<"\t-s single word\t Check for a singal word."<<endl;
    cout<<"\t-f filename\t Check for a whole txt file and output a new file in the same floder."<<endl;
    cout<<"\t--help\t\t Display this help information."<<endl;
}