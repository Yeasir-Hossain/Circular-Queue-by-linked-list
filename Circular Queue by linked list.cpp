#include<iostream>
#include<stdlib.h>
using namespace std;
int s=100;
typedef struct node
{
    int data;
    struct node *next;
} Queue;

class Queuell
{
private:
    Queue *Front,*Rear;
public:
    Queuell();
    void enQueue(int info);
    void deQueue();
    void traverse();
};
Queuell::Queuell()
{
    Front=Rear=NULL;
}
void Queuell::enQueue(int info)
{
    Queue *newnode;
    newnode=(Queue*)malloc(sizeof(Queue));
    if(newnode==NULL)
    {
        cout<<"Allocation failed.";
        return;
    }

    if(Front==NULL)
    {
        newnode->data=info;
        newnode->next=NULL;
        Front=Rear=newnode;
        cout<<"Successfully Inserted."<<endl;
        return;
    }
    else
    {
        newnode->data=info;
        newnode->next=NULL;
        Rear->next=newnode;
        Rear=newnode;
         cout<<"Successfully Inserted."<<endl;
        return;
    }

}
void Queuell::deQueue()
{
    Queue *temp;
    if(Front==NULL)
    {
        cout<<"No List Here.";
        return;
    }
    else if(Front==Rear)
    {
        Front=Rear=NULL;
         cout<<"Successfully Deleted."<<endl;
        return;
    }
    else
    {
        temp=Front;
        Front=temp->next;
        free(temp);
         cout<<"Successfully Deleted."<<endl;

    }
}
void Queuell::traverse()
{
    Queue *i;
    cout<<"The Linked List is:"<<endl;
    for(i=Front; i!=NULL; i=i->next)
    {
        cout<<i->data<<endl;
    }
    system("PAUSE");
}
int main()
{
    Queuell obj;
    int ch=0,x,sl=0;
    while(1)
    {    cout<<"......QUEUE Operation......"<<endl
        <<"1.Insert into Queue."<<endl
        <<"2.Delete from Queue."<<endl
        <<"3.Traverse."<<endl
        <<"4.Exit."<<endl
        <<"Enter choice:";


        cin>>ch;
        switch(ch)
        {

        case 1:
        {
            sl++;
            if(sl>=s)
                {cout<<"Memory full.";
                break;
                }
            else
            {
            cout<<"Enter data:";
            cin>>x;
            obj.enQueue(x);
            system("CLS");
            break;
            }
        }
        case 2:
        {
            obj.deQueue();
            system("CLS");
            break;
        }
        case 3:
        {
            obj.traverse();
            system("CLS");
            break;
        }
        case 4:
        {
            exit(0);
        }
        }
    }
}
