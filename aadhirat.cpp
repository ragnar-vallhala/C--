#include <iostream>
#define LOG(x) std::cout<<x<<std::endl;
#define LOGL(x) std::cout<<x;
class Node{
int data;
Node* next = nullptr;

public:
    Node(int num){
        this->data=num;
    }

    friend class LL;
};

class LL{

Node* head = nullptr;

public:
    LL() = default;

    void insert(int n){
        Node* nn = new Node(n);
        if(this->head==nullptr){
            head=nn;
        }
        else{
            Node* temp = this->head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next = nn;
        }
    }

    void print(){
        if(this->head==nullptr){
            return;
        }
        else{
            Node* temp = this->head;
            while(temp->next!=nullptr){
                LOGL(temp->data);
                LOGL("\t");
                temp=temp->next;
            }
            LOGL(temp->data);
            
        }
    }

    void sort(){
        if(head==nullptr)return;
        else{
            Node* temp = this->head;
            while(temp->next!=nullptr){
                Node* tempNext = temp->next;
                while(tempNext!=nullptr){
                    if(temp->data>tempNext->data){
                        int d = temp->data;
                        temp->data = tempNext->data;
                        tempNext->data = d;
                    }
                    tempNext=tempNext->next;
                }
                temp = temp->next;
            } 
        }
    }


};



int main(){

   LL l;
   l.insert(5);
   l.insert(1005);
   l.insert(115);
   l.insert(15);
   l.insert(105);
   l.sort();
   l.print();
}