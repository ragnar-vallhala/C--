#include <iostream>
#include <fstream>


int main(){
    std::ifstream filein;
    filein.open("data.glsl");
    
    int n = filein.gcount();
    filein.close();
    std::ifstream filein;
    filein.open("data.glsl");
    char* temp = new char[n+1];
    
    temp[n] = '\0';
    filein.read(temp,n);

    
    
    std::cout<<temp<<std::endl<<filein.gcount();

}