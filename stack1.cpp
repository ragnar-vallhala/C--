#include <iostream>
using namespace std;

class Node{
int data;
Node* next=nullptr;

public:

    Node(int num){
        data = num;
    }

    friend class LL;

};

class LL{
Node* head=nullptr;

public:
    LL()=default;

    void insertEnd(int n){
        
        Node* nn =new Node(n);
        if(head==nullptr){
            head = nn;
        }
        else{
            Node* curr = head;
            while(curr->next!=nullptr){
                curr = curr->next;
            }
           curr->next  = nn;

        }
    }

    void insertBegin(int n){
        Node* nn =new Node(n);
        if(head==nullptr){
            head = nn;
        }
        else{
            Node* temp = head;
            head = nn;
            nn->next = temp;
        }
    }

    void sortedInsert(int n){
        //this->print();
       Node* nn =new Node(n);
        if(head==nullptr){
            head = nn;
        } 
        else{
            Node* curr = head;
            if(curr->data>=n){
                Node* temp = head;
                head = nn;
                head->next = temp;
            }
            else{
                while(curr->next!=nullptr && curr->next->data<=n){ 
                    curr = curr->next;
                }
                Node* temp = curr->next;
                curr->next = nn;
                curr->next->next = temp;
                
            }

        }
    }

    void remove(int n){
        
        if(head==nullptr)return;
        else{
            Node* curr = head;
            while(curr->next!=nullptr && curr->next->data!=n){
                curr = curr->next;
            }
            if(curr->next==nullptr)return;
            else{
                Node* temp = curr->next->next;
                curr->next = temp;
            }
        }
    }

    void print(){
        Node* curr = head;
        if(curr==nullptr) return;
        while((*curr).next!=nullptr){
            cout<<(*curr).data<<">>";
            curr = (*curr).next;
        }
        cout<<(*curr).data<<endl;
    }


};



int main(){
    LL l;


    l.sortedInsert(5);
    l.sortedInsert(4);
    l.sortedInsert(3);
    l.sortedInsert(9);
    l.sortedInsert(2);
    l.sortedInsert(9);
    l.sortedInsert(5);
    l.remove(4);


    


    l.print();
    
}