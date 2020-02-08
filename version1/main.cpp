#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Levenshtein{
    private:
        string source,correct;
        int** Larray;
        // 计算三数最小值的函数
        int min(int a,int b,int c){
            if(a<b){
                if(a<c){
                    return a;
                }
                else{
                    return c;
                }
            }
            else{
                if(b<c){
                    return b;
                }
                else{
                    return c;
                }
            }
        }
    public:
        // 构造函数
        Levenshtein(string source_, string correct_){
            source = source_;
            correct = correct_;
            Larray = new int*[source.length()+1];
            for(int i=0;i<source.length()+1;i++){
                Larray[i] = new int [correct.length()+1]; 
            }
            for(int i=0;i<source.length()+1;i++){
                Larray[i][0] = i;
            }
            for(int j=1;j<correct.length()+1;j++){
                Larray[0][j] = j;
            }
        }
        // 复制构造函数
        Levenshtein(Levenshtein& last){
            source = last.source;
            correct = last.correct;
            for(int i=0;i<source.length()+1;i++){
                Larray[i] = new int [correct.length()+1];
            }
            for(int i=0;i<source.length()+1;i++){
                for(int j = 0;j<correct.length()+1;j++){
                    Larray[i][j] = last.Larray[i][j];
                }
            }
        }
        //析构函数
        ~Levenshtein(){
            for(int i=0;i<source.length()+1;i++){
                delete [] Larray[i];
            }
            delete [] Larray;
        }
        // Levenshtein距离表计算函数，返回两个字符串的Levenshtein的距离
        int calculate(){
            for(int i = 1;i<source.length()+1;i++){
                for(int j = 1;j<correct.length()+1;j++){
                    if(source[i-1] == correct[j-1] ){
                        Larray[i][j] = min(Larray[i-1][j]+1,Larray[i][j-1]+1,Larray[i-1][j-1]);
                    }
                    else{
                        Larray[i][j] = min(Larray[i-1][j]+1,Larray[i][j-1]+1,Larray[i-1][j-1]+1);
                    }
                }
            }
            return Larray[source.length()][correct.length()];
        }
};

//此类还须优化，如何在edit算法中不用存储一个word的数组，是否可以通过文件指针操作来节约内存
//考虑是否另外构建一个类来直接将读好的vocabulary数组传入节省文件开闭和创建数组的开销
//考虑是否加入非法字符检测系统
class Check{
    private:
        ifstream dictionary;
        string wrong_word;
        vector<int> times;
        vector<string>vocabularies;
        //找出list中最小数的index，如果相同给出第一个
        int findmin();
    public:
        //构造函数
        Check(string word);
        //析构函数
        ~Check();
        //编辑错误字符返回正确字符的函数
        string edit();
};
int Check::findmin(){
    int min=times[0];
    int index = 0;
    for(int i = 1;i<times.size();i++){
        if(times[i]<min){
            min = times[i];
            index = i;
        }
    }
    return index;
}
Check::Check(string word):wrong_word(word),dictionary("./textfiles/vocabulary.txt",ios::in){
}
Check::~Check(){
    dictionary.close();
}
string Check::edit(){
    if(dictionary){
        string correct_word;
        while(dictionary>>correct_word){
            vocabularies.push_back(correct_word);
            Levenshtein llist(wrong_word,correct_word);
            times.push_back(llist.calculate());
        }
        return vocabularies[findmin()];
    }
    else{
            cerr<<"wrong";
    }
}

int main(){
    string a;
    cin>>a;
    Check me(a);
    cout<<me.edit();
    return 0;
}