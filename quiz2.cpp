#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void subString(string str,string temp, int l, int m, vector<string>&sub){
    if(m==l) sub.push_back(temp);
    else{

        subString(str,temp,l,m+1,sub);
        temp.append(1,str[m]);
        subString(str,temp,l,m+1,sub);

    }
} 


int main(){
    string str = "ABC";     //for testing only
    cin>>str;
    int l = str.length();
    vector<string> sub{}; 

    subString(str,"",l,0,sub);

    //cout<<sub.size()<<endl;
    sort(sub.begin(),sub.end());
    for(int i=0;i<sub.size()-1;i++){
        cout<<sub[i]<<" ";
    }
    cout<<sub[sub.size()-1];
    
}