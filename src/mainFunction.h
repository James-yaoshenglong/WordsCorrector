#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <string>
#include <vector>
using namespace std;

const string VOCABULARY_FILE = "vocabulary.txt";

int findmin(vector<int>);//find the min distance in distanceList

class SingalCorrector{
    private:
        string sourceWord;
        vector<string> vocabularyList;
        vector<int> distanceList;
        friend int findmin(vector<int>);//find the min distance in distanceList 
        void output(int);//print all the words with the min distance
    public:
        SingalCorrector(char*);
        void start(); 
};

class FileCorrector{
    private:
        string fileName;
        string outputName;
        vector<string> vocabularyList;
        vector<int> distanceList;
        void split(const string&, string&, string&);
        friend int findmin(vector<int>);//find the min distance in distanceList 
        void output(const string&, const string&, ofstream&, bool);//output finection,the ofstream should not use const!!
    public:
        FileCorrector(char*);
        void start();
};

void giveHelp();

#endif