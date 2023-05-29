#include <iostream>
#include <vector>

int max(std::vector<int> &vec){
    int mx=vec[0];
    for(int i{};i<vec.size();i++){
        if(mx<vec[i]) mx=vec[i];
    }
    return mx;
}


template <typename T>
class dynamicArray{

public:
    dynamicArray() = default;
    ~dynamicArray(){
        delete m_arr;
        m_arr = nullptr;
    }

    void insert(T num){
        if(m_capacity>m_size){
            m_arr[m_size] = num;
            m_size++;
        }
        else{
            T *arr = new T[(int)(m_capacity*1.5)];
            for(int i{};i<m_capacity;i++){
                arr[i] = m_arr[i];
            }
            m_capacity*=1.5;
            m_arr = arr;
            m_arr[m_size] = num;
            m_size++;
        }
    }
    T pop(){
        T num=40;
        if(m_size>0){
            num = m_arr[m_size-1];
            m_size--;
        }
        
        if((float)m_size<(float)m_capacity/2){
            T *arr = new T[(int)(m_capacity/2)+1];
            for(int i{0};i<m_size;i++){
                arr[i] = m_arr[i];
            }          
            m_capacity=m_capacity*0.5;
            m_capacity++;
            m_arr = arr;
        }
        return num;
        
    }
    T front()const {
        if(m_size>=0){
            return m_arr[0];
        }
        else{
            return (T)404;
        }
        
    }

    T rear()const {
        if(m_size>=0)return m_arr[m_size-1];
        else return (T)404;
        
    }

    int size() const{
        return m_size;
    }

    int capacity() const{
        return m_capacity;
    }
    void print(){
        for(int i{};i<m_size;i++){
            std::cout<<m_arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void empty(){
        free(m_arr);
        m_arr = new T[5]{};
        m_size=0;
        m_capacity = 5;
    }

private:
    T *m_arr = new T[5]{};
    unsigned int m_size{0};
    unsigned int m_capacity{5};


};

int main(){
    
    dynamicArray<int> stk;
    std::vector<int> vec{0};
    int n;
    std::cin>>n;
    for(int i{};i<n;i++){
        int num;
        std::cin>>num;
        if(num==1){
            stk.insert(num);
        }
        else{
            vec.push_back(stk.size());
            stk.empty();
        }

        // std::cout<<"Round "<<i<<"  "; stk.print();
        // std::cout<<"--------------------------"<<std::endl;
        // for(auto i:vec){
        //     std::cout<<i<<" ";
        // }
    }
    vec.push_back(stk.size());
    stk.empty();
    //std::cout<<"--------------------------"<<std::endl;
    // for(auto i:vec){
    //     std::cout<<i<<" ";
    // }
    std::cout<<max(vec)<<std::endl;
}
