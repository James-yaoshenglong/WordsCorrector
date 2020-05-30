#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <string>
using namespace std;

class Levenshtein{
    private:
        string source,correct;
        int** Larray;
        int min(int,int,int); // 计算三数最小值的函数
    public:
    Levenshtein(const string&, const string&);
    ~Levenshtein();
    int calculate();// Levenshtein距离表计算函数，返回两个字符串的Levenshtein的距离
};


#endif