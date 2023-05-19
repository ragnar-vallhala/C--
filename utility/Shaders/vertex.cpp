#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int> arr;

    for(int i{};i<2*n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    set<int> left;
    set<int> right;
    for(int i{n};i<2*n;i++){
        for(int j{};j<n;j++){
            if(arr[j]>=arr[i]){
                left.insert(j);
                right.insert(i);
            }
        }
    }
    auto it1 = left.begin();
    int suml{},sumr{};
    for(int i{};i<left.size();i++){
        suml+=*it1;
        it1++;
    }

    auto it2 = right.begin();
    cout<<endl;
    for(int i{};i<right.size();i++){
        sumr+=*it2;
        it2++;
    }
    if(right.size()<left.size()){
        sumr++;
    }
    cout<<sumr-suml<<endl;
}