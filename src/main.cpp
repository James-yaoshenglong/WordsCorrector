#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    //two shell command argument
    if(argc > 3){
        std::cout<<"More arguments than needed!"<<std::endl;
        exit(1);
    }
    else if(argc < 3){
        std::cout<<"Need more arguments!"<<std::endl;
        exit(1);
    }
    else if(strcmp(argv[1], "--help") == 0){
        std::cout<<"help"<<std::endl;
        return 0;
    }
    else if(strcmp(argv[1], "-s") == 0){// check single word
        char* word = argv[2];
        std::cout<<"signgle words check"<<std::endl;
        return 0;
    }
    else if(strcmp(argv[1], "-f") == 0){// check a file
        char* filename = argv[2];
        std::cout<<"File check"<<std::endl;
        return 0;
    }
    else{
        std::cout<<"argument not finded"<<std::endl;
        //help()
        exit(1);
    }
    return 0;
}