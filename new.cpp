#include <iostream>
using namespace std;

class Node{

private:   
    int data;
    Node* next = NULL;

public:

    /*constructor*/
    Node(int num){
        this->data = num;
    }

    friend class LL;
};

class LL{
private:
    Node* head = nullptr;

public:
    /*constructor*/
    LL() = default;

    void add(int num){
        Node* nn = new Node(num);
       
        if(this->head == nullptr) this->head = nn;
        else{
            Node* temp = this->head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void print(){
        if(this->head==nullptr)return;
        else{
            Node* temp = this->head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }


};


int main(){
    
    LL l;
    l.add(5);
    l.add(8);
    l.add(6);
    l.add(3);
    l.add(5);
    l.print();



    


}