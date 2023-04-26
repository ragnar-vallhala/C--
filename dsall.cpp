#include <iostream>


/*
Node class is the link of the linked-list
*/
class Node{

private:

    /*
    data is of type integer
    */
    int data;

    /*
    Points to next Node
    */
    Node* next = nullptr;

public:

    /*
    Default constructor
    */
    Node() = default;

    /*
    Constructor
    @param num : data of new Node
    */
    Node(int num){
        this->data = num;
    }
    

    /*
    Takes input for node
    */
    void in(){
        std::cin>>this->data;
    }

    /*
    Prints the data of node
    */
    void out(){
        std::cout<<this->data;
    }

    /*
    Return data of the Node
    */
    int rdata(){
        return this->data;
    }


    /* 
    Allows access to LL class to the private members of node
    */
    friend class LL;
};

class LL{

private:

    Node* head  = nullptr;

public:

    /*
    Default contructor
    */
    LL() = default;

    /*
    Adds node to the end of the LL
    @param num : data of the new node
    */
    void append(int num){

        Node* nn = new Node(num);

        if(this->head == nullptr){
            this->head = nn;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }
    /*
    Inserts element to the beginning of the LL
    @param num: data of new Node
    */
    void insertBegin(int num){
        Node* temp = this->head;
        Node* nn = new Node(num);
        this->head = nn;
        head->next = temp;
    }

    /*
    Adds node to the end of the LL
    Takes input from terminal
    */
    void add(){
        Node *nn = new Node();
        nn->in();

        if(this->head == nullptr){
            this->head = nn;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    /*
    @returns
    sum of data of all nodes
    */
    int sum(){
        int num{};


        if(this->head == nullptr){
            return num;
        }
        else{
            Node* temp = head;
            while(temp!=nullptr){
                num+= temp->rdata();
                temp = temp->next;
               
            }

            return num;
        }
    }


    /*
    Prints the data in the linked list between a range
    */
    void print(){
        Node* temp = this->head;
        while(temp!=nullptr){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        
        }
    }


    /*
    Returns nth node in the LL
    @param n: index of node
    */
    int fetch(int n){
        if(this->head==nullptr){
            return -1;
        }
        else{
            
            Node* temp = this->head;
            int p=0;
            while(p<n-1 && temp!=nullptr){
                temp = temp->next;
                p++;
            }
            if(temp!=nullptr) return temp->data;
            else return -1;
        }
    }

    /*
    @returns bool if LL is palindrome
    */
    bool isPalindrome(){
        if(this->head == nullptr) return true;
        else{

            Node* curr = this->head;
        }
    }

    /*
    Deletes nth Node
    @param n: index of node to bbe removed
    */
    void remove(int n){
        Node* curr = this->head;
        if(curr == nullptr){
            return;
        }
        else if(n==1){
            this->head = this->head->next;
        }
        else{
            int p=0;
            while(p<n-2 && curr->next!=nullptr){
                p++;
               curr = curr->next;
            }
            if(curr->next!=nullptr){
                Node* res = curr->next;
                curr->next = curr->next->next;
                delete res;
            }
            else{
                return;
            }
        }
    }



    /*
    Inserts node at specific index
    @param num: data of the new node
    @param n: index of the new node
    */
    void put(int num, int n){
        n+=1;
        Node* nn  = new Node(num);
        if(this->head==nullptr){
            return;
        }
        else{
            
            Node* temp = this->head;
            int p=1;
            while(p<n-1 && temp!=nullptr){
                temp = temp->next;
                p++;
            }
            if(p==1 && n == 1){
                Node* res =this->head;
                this->head = nn;
                this->head->next = res;
                return;
            }
            if(temp!=nullptr) {
                Node* res = temp->next;
                temp->next = nn;
                temp->next->next = res;
            }
            else return;
        }
    }


    /*
    Returns size of the LL
    */
    int size(){
        int p=0;
        Node* temp = this->head;

        while(temp!=nullptr){
            temp = temp->next;
            p++;
        }
        return p;

    }

    /*
    Returns pointer to a reversed LL
    */
    LL* reverse(){
        LL* rev = new LL;

        Node* temp = this->head;

        while(temp!=nullptr){
            rev->insertBegin(temp->data);
            temp = temp->next;
        }

        return rev;
    }
};

int main(){


    LL n;
    int p;
    std::cin>>p;

    for(int i=0;i<p;i++){
        n.add();
    }
    
    int k;
    std::cin>>k;
    n.remove(k+1);
    n.print();


}