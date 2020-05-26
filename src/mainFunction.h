#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <string>
using namespace std;

class SingalCorrector{
    private:
        string sourceWord;
    public:
        SingalCorrector(char*);
        void start(); 
};

class FileCorrector{
    private:
        string fileName;
    public:
        FileCorrector(char*);
        void start();
};

void giveHelp();

#endif