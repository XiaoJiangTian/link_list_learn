#include <iostream>
using namespace std;


class node //创建一个适合双向链表的结点类型
{
public:
    int data;
    node *pre;
    node *next;
};
node *head;//声明头结点为全局变量
node *create_newnode(int n)//创建一个节点，对其数据和指针域赋值，并获得指向该结点的指针
{
    node *new_node = new node;
    new_node->data=n;
    new_node->next=NULL;
    new_node->pre=NULL;
    return new_node;
}


void insert_at_head(int n)
{
    node *new_node = create_newnode(n);
    if(head==NULL)
    {
        head = new_node; //如果头结点为空，头结点首先指向最先创建的节点
        return ;
    }
    new_node->next=head;//将头结点地址赋值给新节点的后指针域
    head->pre=new_node;//将新节点地址赋值给原节点的前指针域，实现在头部插入元素
    head = new_node;//让新节点称为头结点
}

void insert_at_tail(int n)
{
    node *new_node= create_newnode(n);
    if(head==NULL)
    {
        head=new_node;
        return ;
    }
    node *temp=head; //因为头结点指向不能变，所以新建一个节点临时存放指向节点的地址
    while(temp->next!=NULL)//将该指针指向的节点移到最后一个节点，
    {
        temp = temp->next;
    }
    temp->next=new_node;//因为叉在最后，所以将原尾结点的后指针域指向新节点，
    new_node->pre=temp;//新节点的前指针域指向原尾结点
}

void print()
{
    node *temp=head;
    if(temp==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";//通过移动指针，改变其指向的节点，并输出相应节点的数据域
        temp = temp->next;
    }
}

void reverse_print()
{
    node *temp = head;
    if(temp==NULL)
    {
        return;
    }
    while(temp->next!=NULL)//先让临时指针指向尾结点，
    {
        temp = temp->next;
    }
    cout<<"reverse print:"<<endl;
    while(temp!=NULL)//从尾节点开始打印，并将节点指针往前面的节点移动
    {
        cout<<temp->data<<" ";
        temp = temp->pre;
    }
}

int main()
{
    head =NULL;
    insert_at_head(3);
    insert_at_head(1);
    insert_at_head(5);
    insert_at_head(2);
    print();
    cout <<endl;
    insert_at_tail(10);
    print();

    reverse_print();
    cout << "over!" << endl;
    return 0;
}
