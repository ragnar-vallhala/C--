#include <iostream>
#include <set>
#include <vector>
using namespace std;

int step(string s){
    set<string> vec;
    for(int i{};i<s.length()-1;i++){
        char arr[2]{s[i],s[i+1]};
        string st = arr;
        vec.insert(st);
    }

    return vec.size();
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        cin>>n;
        cin>>s;
        cout<<step(s)<<endl;
    }
    
}