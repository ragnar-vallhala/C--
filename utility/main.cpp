#include <iostream>
#include <fstream>
#if 1
#define LOG(x) std::cout<<x<<std::endl;
#else
#define LOG(x)
#endif


void LoadFile(const char* path, std::string &str){
    std::ifstream in;
    in.open(path);

    if(!in.is_open()){
        LOG("Failed to open "+(std::string)path);
        return;
    }
    str = "";
    while(!in.eof()){
        char temp[500];
        in.getline(temp,500);
        str+=(std::string)temp+'\n';
    }
    str+='\0';
}


int main(){
    std::string data;
    const char* dat;
    LoadFile("Shaders/vertex.glsl",data);
    dat = data.c_str();
    LOG(dat);

    return 0;
}