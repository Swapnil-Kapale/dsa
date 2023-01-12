#include<iostream>
using namespace std;

struct node{
   int data;
   node *next;
};

class sll{

    public:
    node *head,*nn;
    sll(){
        head=nn=nullptr;
    }
    //functions 
    void insert_beg(int data){
        nn=new node;
        nn->data=data;
        nn->next=nullptr;
        if(head==nullptr){
            head=nn;
        }
        else{
            nn->next=head;
            head=nn;
        }
    }
    void insert_end(int data){
        nn=new node;
        nn->data=data;
        nn->next=nullptr;
        if(head==nullptr){
            head=nn;
        }else{
            node*t=head;
            while(t->next!=nullptr){
                t=t->next;
            }
            t->next=nn;
        }
    }

    void delete_beg(){
        if(head==nullptr){
            cout<<"list empty";
        }else{
            node *t=head;
            head=head->next;
            delete(t);
        }
    }

    void display(){
        node *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }


};

int main(){
    sll stack,queue;
    char op;
    int data;
    do{
        cout<<"\n\nstack opertions\n";
        cout<<"\n 1.push";
        cout<<"\n 2.pop";
        cout<<"\n 3.dispaly";
        cout<<"\n\nQueue opertions\n";
        cout<<"\n 4.enq";
        cout<<"\n 5.deq";
        cout<<"\n 6.dispaly";
        cout<<"\n>";
        cin>>op;

        switch(op){
            case '1':cout<<"/Enenter data: ";cin>>data;stack.insert_beg(data);break;
            case '2':stack.delete_beg();break;
            case '3':stack.display();break;
            case '4':cout<<"/Enenter data: ";cin>>data;queue.insert_end(data);break;
            case '5':queue.delete_beg();break;
            case '6':queue.display();break;
            default :cout<<"end";break;
        }


    }while(op!='7');
    return 0;
}
