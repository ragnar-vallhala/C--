#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i{};i<n;i++){
        int p;
        cin>>p;
        vec.push_back(p);

    }


    vector<int> mx;

    for(int i{};i<n-1-vec[vec.size()-1];i++){
        auto num = max_element(vec.begin()+i,vec.begin()+i+vec[vec.size()-1]);

        mx.push_back(*num);
    }

    for(int i{};i<mx.size();i++){

        cout<<mx[i]<<" ";
    }



}