#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int num(int n,int k){
    if(n==1) return 1;
    else{
        return (num(n-1,k)+k-1)%n+1;
    }
}

int main(){


    int a,b;
    cin>>a>>b;
    cout<<num(a,b)<<endl;

    
}