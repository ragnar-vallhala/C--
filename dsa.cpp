#include <iostream>

/*
Returns the sum the digits of the given number
@param num: number whose digits is to be summed
*/
int digitSum(int num){
    int sum{};

    while(num>0){
        sum+=(num%10);
        num/=10;
    }

    return sum;
}


/* 
Returns true if the num is good
@param left: the number to be checked
@param right: 
*/
bool goodNumber(int left, int right){
   
}

/*
Returns true if digit d is conatined in the number num
@param num: number to be checked  in
@param d: digit to be checked
*/
bool digitChecker(int num, int d){
    while(num>0){
        if(num%10==d) return true;
        else num/=10;
    }
    return false;
}


int main(){

    int a,b,d;
    std::cin>>a>>b>>d;
    
    for(int i{a};i<=b;i++){
        if(!digitChecker(i,d) && goodNumber(i)) std::cout<<i<<" ";
    }
    
}