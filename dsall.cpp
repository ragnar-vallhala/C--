#include <iostream>
#include <vector>
#include <algorithm>
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
    Prints the data in the linked list
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
        if(this->head==nullptr || n==0){
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
        bool flag = true;
        if(this->head == nullptr) return flag;
        else{
            int len = this->size();
            for(int i{1};i<=len/2;i++){
                if(this->fetch(i)!=this->fetch(len+1-i)){
                    flag=false;
                    break;
                }
                
            }
        }
        return flag;
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


    /*
    Overloads the == operator
    @param &l: reference to the LL to be compared
    */
    bool operator==(LL &l){
        if(this->size()!=l.size()) return false;
        else if(this->head == nullptr && l.head == nullptr) return true;
        else{
            Node* temp1 = this->head;
            Node* temp2 = l.head;

            while(temp1->next!=nullptr){
                if(temp1->data!=temp2->data) return false;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }


    /*
    Delete the duplicate nodes
    */
    void deleteDuplicates(){
        if(this->head == nullptr) return;
        else{
            Node* temp = this->head;
            
            while(temp->next!=nullptr && temp!=nullptr){

                Node* iter = temp;
                while(iter->next!=nullptr && iter!=nullptr){
            
                    if(temp->data == iter->next->data){
                        if(iter->next->next!=nullptr) iter->next = iter->next->next;
                        else iter->next = nullptr;
                    }
                    else{
                        iter = iter->next;
                    }  
                }

                if(temp->next!=nullptr)temp = temp->next;
                
                
            }
            
        }
    }

    /*
    Sorted Merge two linked lists
    @param l2: pointer to second linked list
    @return merged list
    */
    LL *sortedMerge( LL *l2)
    {   LL* l1 = this;
        LL* nl = new LL();

        Node *temp1 = l1->head;
        Node *temp2 = l2->head;
        std::cout<<(temp2!=nullptr)<<"case"<<std::endl;

        while(temp1!=nullptr && temp2!=nullptr){
            
            if(temp1->data>=temp2->data){
                nl->append(temp2->data);
                temp2 = temp2->next;
            }
            else{
                nl->append(temp1->data);
                temp1 = temp1->next;
            }
        }
        while(temp1!=nullptr){
            
            nl->append(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2!=nullptr){
            nl->append(temp2->data);
            temp2 = temp2->next;
        }
        

        return nl;
    }

    /*
    @return value of LL written in decimal
    */
    long toDec(){
        long sum=0;
        if(this->head==nullptr) return sum;
        else{
            Node* temp = this->head;

            while(temp!=nullptr){
                sum = sum*10 + temp->data;
                temp = temp->next;
            }
        } 
        return sum;

    }

    /*
    Folds the linked list
    @return folded LL
    */
    LL* fold(){
        int n = this->size();
        if(n==0) return nullptr;
        else{
            LL* nl = new LL();
            for(int i{1};i<=n/2;i++){
                nl->append(this->fetch(i));
                nl->append(this->fetch(n+1-i));
            }

            if(n%2!=0){
                nl->append(this->fetch(n/2+1));
            }

            return nl;
        }

    }


    /*
    Unfolds a linked list
    */
    LL* unfold(){
        if( this->head == nullptr) return nullptr;
        else{
            LL* nl = new LL();
            int n = this->size();
            for(int i{1};i<=n;i+=2){
                nl->append(this->fetch(i));
            }
            int p = nl->size();
            for(int i{2};i<=n;i+=2){
                nl->put(this->fetch(i),p);
            }

            return nl;
        }
    }

    /*
    @return index of node containing n
    @param n: data to be serached
    */
    int find(Node* n){
        int p=0;
        if(this->head==nullptr) return 0;
        else{
            Node* temp = this->head;
            while(temp!=nullptr){
                if(temp == n) break;
                p++;
                temp = temp->next;
            }
            if(temp!=nullptr) return p+1;
            else return 0;
        }
    }





    
};




int main(){

    LL n;
    int p;
    std::cin>>p;

    for(int i=0;i<p;i++){
        n.add();
    }



}

