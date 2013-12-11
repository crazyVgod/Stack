#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

typedef struct Node
{
        int data;
        struct Node * next;
}*ListNodeptr,ListNode;

class Stack
{
	private:
        ListNodeptr *top;
        int count;
    public:
        void pop();
        void push(int value);
        void show();
        Stack(int cap)
        {
                ListNodeptr p,q;
                int i=cap-1;
                q=(ListNodeptr)malloc(sizeof(ListNode));
                q->next=NULL;
                while(i>=0)
                {
                        p=(ListNodeptr)malloc(sizeof(ListNode));
                        if(!p)
                        {
                                cout<<"内存分配失败\n";
                        }
                        else
                        {
                            p->data=0;
                            p->next=q->next;
                            q->next=p;
                        }
                        i--;
                }
                *top=q;
                count=cap;
        }
        ~Stack()
        {
             ListNodeptr p=(*top),q=p->next;
                 while(q)
                 {
                         p->next=q->next;
                         free(q);
                         q=p->next;
                 }
        }
};

void Stack::pop()
{
        if((*top)->next)
        {
                ListNodeptr q=(*top)->next;
                (*top)->next=q->next;
                free(q);
                count--;
        }
        else
                cout<<"您的操作没有成功！没有剩余元素!"<<endl;
}

void Stack::push(int value)
{

        ListNodeptr p=(ListNodeptr)malloc(sizeof(ListNode));
                        if(!p)
                        {
                                cout<<"内存分配失败\n";
                        }
                        else
                        {
                            p->data=value;
                            p->next=(*top)->next;
                            (*top)->next=p;
                            count++;
                        }
}

void Stack::show()
{
        ListNodeptr p=*top;
        while(p->next)
        {
                ListNodeptr q=p->next;
                cout<<q->data<<" ";
        }
        cout<<endl;
}

int main()
{
        Stack *st = new Stack(10);
        (*st).show();
        for(int i=0;i<9;i++)
           (*st).push(i);
        (*st).show();
        (*st).pop();
        (*st).show();
        return 0;
}

