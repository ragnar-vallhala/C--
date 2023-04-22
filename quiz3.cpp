#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int path(int a, int b){
    //std::cout<<a<<' '<<b<<endl;
    if(a==0||b==0||a==1||b==1) return 1;
    else return (path(a-1,b)+path(a,b-1));
}


int main(){

int a,b;
cin>>a>>b;
cout<<path(a,b);
    
}