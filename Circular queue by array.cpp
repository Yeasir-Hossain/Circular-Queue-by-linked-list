#include<iostream>
#include<stdlib.h>
using namespace std;
class Q
{
private:
    int F,rear;
    int arraysize,*arr;
public:
    Q(int r)
    {
        F=rear=-1;
        arraysize=r;
        arr=(int *)malloc(arraysize*4);
    }
    void enque(int x);
    void dequee();
    void display();
};
void Q::enque(int x)
{
    if(F==-1)
    {
        arr[0]=x;
        F=rear=0;
        return;
    }
    else if((F==0&&rear==arraysize-1)||(F==rear+1))
    {
        cout<<"No space"<<endl;
        system("PAUSE");
        return;
    }
    else if(rear==arraysize-1)
    {
        rear=0;
        arr[rear]=x;
        return;
    }
    else
    {
        rear=rear+1;
        arr[rear]=x;
    }

}
void Q::dequee()
{
    if(F==-1)
    {
        cout<<"Underflow"<<endl;
        system("PAUSE");
        return;
    }
    if(F==rear)
    {
        F=rear=-1;
    }
    if(F==arraysize-1)
    {
        F=0;
    }
    else
        F++;

}
void Q::display()
{
    int i,co=0;
    if(F==-1)
    {
        cout<<"The list is empty"<<endl;
        system("PAUSE");
        return;
    }
    else if(F>rear)
    {
        co++;
        for(i=F; i<arraysize; i++)
        {
            co++;
            cout<<"The data number "<<co<<" is :"<<arr[i]<<endl;
        }
        for(i=0; i<=rear; i++)
        {
            co++;
            cout<<"The data number "<<co<<" is :"<<arr[i]<<endl;
        }
    }
    else
    {

        for(i=F; i<=rear; i++)
        {
            co++;
            cout<<"The data number "<<co<<" is :"<<arr[i]<<endl;
        }
    }
    system("PAUSE");
}
int main()
{
    int ch=0,z;
    cout<<"Enter size:";
    cin>>z;
    Q myQ(z);

    while(1)
    {
        cout<<"---MENU---"<<endl;
        cout<<"1.ENQUEUE"<<endl;
        cout<<"2.DEQUEUE"<<endl;
        cout<<"3.TRAVERSE"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            int d;
            cout<<"Enter data:";
            cin>>d;
            myQ.enque(d);
            system("CLS");
            break;
        case 2:
            myQ.dequee();
            system("CLS");
            break;
        case 3:
            myQ.display();
            system("CLS");
            break;
        case 4:
            exit(0);
        default:
            cout<<"Choice is out of 1-4.Enter again"<<endl;

        }

    }
}

