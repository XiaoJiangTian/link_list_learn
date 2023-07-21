#include <iostream>
using namespace std;

class point
{
public:
    int data;
    point *p;
};

point * insert(point *head,int data)
{
    point *data_p=new point;
    data_p->data=data;
    data_p->p=head;
    head = data_p; //这里不能delete  data_p相当于把原来形成的结构给删除了，导致后面传入的head里数据变了，一直找不到值为null指针
    return head;//head仍然指向头结点，注意在操作中实现这个原则即可，不需要创建一个temp来代替head操作
}

point *insert_anywhere(point *head,int pos,int data)
{
    point *insert_p = new point; //为新节点开辟一个空间
    insert_p->data=data;//为空间的数据域和指针域赋值
    insert_p->p=NULL; //先给新节点的指针域赋值为null
    if(pos==1)//如果插入在第一个
    {
        insert_p->p=head;
        head = insert_p;
        return head;
    }
    else//在其他位置的情况
    {
        point *data_pos=head;
        for(int i=0;i<pos-2;i++) //这里要注意的是data_pos只是一个指针不是节点本身，指针指向pos-1数据时，对pos-1 pos pos+1这个三个节点的指针域进行交换
        {
            data_pos=data_pos->p;
        }
        insert_p->p=data_pos->p; //将对应节点插入第pos个位置，调整指针域
        data_pos->p=insert_p;

        return head;
    }
}


point *delete_n(point *head,int n)
{
    point *temp = head;
    if(n==1)//如果删除的是头结点，将head指向原头结点的下一个节点，并将原节点delete，这里delete指针的意思是对指针指向的节点内存区域进行释放，因为每次插入都调用了new的
    {
        head = temp->p;
        delete temp;
        return head;
    }
    else
    {
        for(int i =0;i<n-2;i++) //若不是删除原节点，则找到删除节点的前一个节点，对删除节点，和前一个后一个节点的指针域进行变化
        {
            temp = temp->p;//此时temp指向被删除的前一个节点
        }
        point *temp2 = temp->p;//temp2是被删除的那个节点
        temp->p=temp2->p;//让被删除的节点从链表中剥离
        delete temp2;
        return head;
    }
}

point *reverse_link(point *head)//翻转链表
{
    point *pre,*current,*next,*temp; //定义4个指针存储节点的地址数据
    current = head;
    pre= NULL;
    while(current!=NULL)
    {
        next = current->p; //先保存下一个节点的指针信息
        current->p=pre;//改变当前节点指针的指向
        pre=current; //改变后把当前节点变为前一节点
        current=next; //当前节点变为下一节点
    }
    head = pre;//头节点指向原来最后的节点
    return head;
}

void print(point *head)
{
    cout << "list:";
    while(head!=NULL)
    {
        cout<<head->data<<" ";//head是一个指针，指向头结点，可以调用该节点的数据
        head = head->p;
    }
}

void print_reverse(point *head)//递归方式实现打印
{
    if(head==NULL) return;//注意递归的退出条件，，也要注意递归调用的位置否则会导致语句不能执行出来
    cout <<head->data<<" "; //将这里的输出和递归调用交换位置，即先递归后输出，就会实现，逆序打印
    print_reverse(head->p);
}

point *head1=NULL;
void reverse(point *head_temp)
{
    if(head_temp->p==NULL)
    {
        head1 = head_temp;
        return;

    }
    reverse(head_temp->p);
    point *temp = head_temp->p;
    temp->p=head_temp;
    head_temp->p = NULL;

}


void test()
{
    for(int i =0,n=3;i<n;i++)
    {
        int data=0;
        cout<<"the "<<i<<"th number:";
        cin >>data;
        head1 = insert(head1,data);
        print(head1);
        cout <<endl;
    }
    reverse(head1);
    print(head1);
}
int main()
{
    int n=0, data=0;
    point *head=NULL;
    cout<<"please input the number you wanna to insert:"<<endl;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cout<<"the "<<i<<"th number:";
        cin >>data;
        head = insert(head,data);
        print(head);
        cout <<endl;
    }
    cout << "insert data!"<<endl;
    head = insert_anywhere(head,2,10); //实现在第2个位置插入10
    cout<<"delete data!"<<endl;
    head = delete_n(head,3);//删除链表的第三个元素
    print(head);
    cout<<"reverse the link!"<<endl;
    head = reverse_link(head);
    print(head);
    cout <<endl;
    print_reverse(head);
    cout << "over!" << endl;
    test();
    return 0;
}
