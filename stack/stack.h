#include <iostream>
#define _DEFAULT_CAPACITY 5

template<typename T>
class Stack{
public:
    Stack();


private:
    unsigned int m_top=-1;
    unsigned int m_bottom=-1;
    unsigned int m_size = 0;
    unsigned int m_capacity = _DEFAULT_CAPACITY;
    T *m_array = nullptr; 


};


