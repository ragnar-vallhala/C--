#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;


    for(int i{1};i<=n;i++){
        for(int j{i+1};j<=n;j++){
            if(((j*(j+1)-i*(i+1))/2)%((j-i)+1)!=0){
                cout<<i<<" "<<j<<" "<<j*(j+1)-i*(i+1)<<endl;
            }
        }
    }
}