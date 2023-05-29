#include<stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(vector<int> &vec){
    int mx=vec[0];
    for(int i{};i<vec.size();i++){
        if(mx<vec[i]) mx=vec[i];
    }
    return mx;
}

int main() {
    while(1){
        stack<int> stk;
        vector<int> vec{0};
        int n;
        cin>>n;
        for(int i{};i<n;i++){
            int num;
            cin>>num;
            if(num==1){
                stk.push(num);
            }
            else{
                vec.push_back(stk.size());
                
            }
        }
        vec.push_back(stk.size()-(vec.size()>1?vec[vec.size()-1]:0));
       
        stk.empty();
        cout<<max(vec)<<endl;
    }
    return 0;
}
