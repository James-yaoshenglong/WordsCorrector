#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <string>
#include <vector>
using namespace std;

const string VOCABULARY_FILE = "vocabulary.txt";

class SingalCorrector{
    private:
        string sourceWord;
        vector<string> vocabularyList;
        vector<int> distanceList;
        int findmin();//find the min distance in distanceList 
        void output(int);//print all the words with the min distance
    public:
        SingalCorrector(char*);
        void start(); 
};

class FileCorrector{
    private:
        string fileName;
        vector<string> vocabularyList;
        vector<int> distanceList;
    public:
        FileCorrector(char*);
        void start();
};

void giveHelp();

#endif