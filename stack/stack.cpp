#include "stack.h"

template <typename T>
inline Stack<T>::Stack()
{
    m_array = new T[m_capacity];
}

int main(){

    Stack<int> stk; 
}