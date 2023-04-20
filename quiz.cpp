#include <iostream>
using namespace std;

bool goodNum(int n){
    int sum{};
    bool d=true;
    while(n>0){
        if(n%10<=sum && d!=true) return false;
        d=false;
        sum+=n%10;
        n/=10;
    }
    return true;
    
}

bool isNP(int n, int d){
    while(n>0){
        if(n%10==d) return false;
        n/=10;
    }
    return true;
}

int main(){

    int n,m,d;
    cin>>n>>m>>d;

    for(int i{n};i<=m;i++){
        if(isNP(i,d)&&goodNum(i)){
            cout<<i<<" ";
        }
    }
  
}