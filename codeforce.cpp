#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> step(int diff,vector<int> &act, vector<int> &exp,vector<int> &ans ){
    ans.clear();
    for(int i{};act.size()>0;i){
        vector<int> delta;
        for(int j{};j<exp.size();j++){
            delta.push_back(abs(act[i]-exp[j]));
        }

        int minimum{delta[0]},minInd{0};
        for(int k{};k<delta.size();k++){
            if(delta[k]<minimum){
                minimum=delta[k];
                minInd=k;
            }
        }

        ans.push_back(exp[minInd]);
        exp.erase(exp.begin()+minInd);
        act.erase(act.begin()+i);

        // cout<<"\nDelta             "<<endl;
        // for(int i{};i<delta.size();i++){
        //     cout<<delta[i]<<" ";
        // } 

        // cout<<"\nExp              "<<endl;
        // for(int i{};i<exp.size();i++){
        //     cout<<exp[i]<<" ";
        // } 

        // cout<<"\nAct              "<<endl;    
        // for(int i{};i<act.size();i++){
        //     cout<<act[i]<<" ";
        // } 


        // cout<<"\nAns              "<<endl;
        // for(int i{};i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // } 

        // cout<<endl;
    }

    return ans;
    
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,diff;
        cin>>n>>diff;
        vector<int> act,exp;
        for(int i{};i<n;i++){
            int num;
            cin>>num;
            exp.push_back(num);
        }

        for(int i{};i<n;i++){
            int num;
            cin>>num;
            act.push_back(num);
        }

        vector<int> ans;
        ans = step(diff,exp,act,ans);

        for(int i{};i<ans.size();i++){
            cout<<ans[i]<<" ";
        } 
        cout<<endl;
    }
    
}