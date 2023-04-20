#include <iostream>
#include <vector>
using namespace std;


class stack{
vector <int> stk;

public:

    stack()=default;

    void push(int n){
        stk.push_back(n);
    }

    void pop(){
        stk.pop_back();
    }

    void print(){
        for(int i{stk.size()-1};i>=0;i--){
            cout<<stk[i]<<"\t";
        }
        cout<<endl;
    }

    int last(){
        return stk[stk.size()-1];
    }

    int first(){
        return stk[0];
    }


};

int main(){
    


}