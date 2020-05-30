#include "Levenshtein.h"

int Levenshtein::min(int a, int b, int c){
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

Levenshtein::Levenshtein(const string& source_, const string& correct_){
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

Levenshtein::~Levenshtein(){
    for(int i=0;i<source.length()+1;i++){
        delete [] Larray[i];
    }
    delete [] Larray;
}

int Levenshtein::calculate(){
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
