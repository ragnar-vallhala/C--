#include <iostream>


class dynamicArray{

public:
    dynamicArray() = default;
    ~dynamicArray(){
        delete m_arr;
        m_arr = nullptr;
    }

    void insert(int num){
        if(m_capacity>m_size){
            m_arr[m_size] = num;
            m_size++;
        }
        else{
            int *arr = new int[m_capacity+m_capacity/2];
            for(int i{};i<m_capacity;i++){
                arr[i] = m_arr[i];
            }
            m_capacity*=1.5;
            m_arr = arr;
            m_arr[m_size] = num;
            m_size++;
        }
    }

    int front()const {
        return m_arr[0];
    }

    int rear()const {
        return m_arr[m_size-1];
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

private:
    int *m_arr = new int[5];
    unsigned int m_size{};
    unsigned int m_capacity{5};


};


using namespace std;
int main(){

    dynamicArray q;
    q.insert(5);
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.print();
    cout<<q.size()<<"   "<<q.capacity();

}