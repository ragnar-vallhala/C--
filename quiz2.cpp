#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


void onFind(int num, vector<int> &n){
    int k=0;
    while(num>=pow(2,k)){
        if((int(pow(2,k)) & num)!=0){
            n.push_back(k);
        }
        k++;
    }

}

int main(){
    string str{"sai"};
    int n=2;
    

    cin>>str;
    n=str.size()+1;
    //sort(str.begin(),str.end());
    
    vector <string> s{};
    while(n--){
        for(int i{};i<pow(2,str.length());i++){
        vector <int> in{};
        onFind(i,in);

        // for(int i{};i<in.size();i++){
        // cout<<in[i]<<" ";
        // }
        // cout<<i<<endl;

        if(in.size()==n){
            string sr{};
            for(int j{};j<in.size();j++){
                
                sr.append(1,str[in[j]]);
            }
            if(!(find(s.begin(), s.end(), sr)!=s.end()))s.push_back(sr);
        }
        }
    }
    
   
   sort(s.begin(),s.end());
    for(int i{};i<s.size();i++){
        cout<<s[i]<<" ";
    }
}