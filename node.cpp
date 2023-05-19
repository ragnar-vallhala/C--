#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next=nullptr;
    Node(int n){
        data=n;
    }
};


void insert(int num,Node* &head){

    Node* nn = new Node(num);
    if(head==nullptr){
        head = nn;
    }
    else if(head->next==nullptr){
        head->next=nn;
    }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nn;
    }
}



void user_insert(Node* &head){
    int num;
    cin>>num;
    Node* nn = new Node(num);
    if(head==nullptr){
        head = nn;
    }
    else if(head->next==nullptr){
        head->next=nn;
    }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nn;
    }
}


void print(Node* &head){
    if(head==nullptr){
        cout<<"Empty"<<endl;
    }
    else if(head->next==nullptr){
        cout<<head->data<<endl;
    }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            cout<<temp->data<<">>";
            temp=temp->next;

        }
        cout<<temp->data;
    }
}



int main(){

    Node* head=nullptr;
    int n;
    cout<<"enter number of links"<<endl;
    cin>>n;
    while(n--){
        user_insert(head);
    }
    print(head);

    return 0;
}