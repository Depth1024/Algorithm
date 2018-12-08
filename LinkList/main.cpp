/*
线性表的链式存储
                */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 定义单链表的一个结点
typedef struct lnode{
    int data;            // 数据域，用来存放数据
    struct lnode *next;  // 指针域，指向单链表结点结构体的指针，用来指向链表中的下一个结点
}LNode,*LinkList;
// LNode是结点的类型，LinkList是指向LNode类型的指针变量，也是“头指针”的类型。

/*
        一条链表的实体部分其实为：LNode-LNode-LNode-LNode-LNode-LNode，但是这样的话，第一个结点的地址没有得到存储，
    这个链表也就无法被找到；
        因此，为了1）存储第一个结点的地址 2）程序的可读性，我们为链表设置一个“头指针”，定义为LinkList类型，如LinkList L。
    (所有结点都一个接一个地连在头指针后面，因此定义了一个头指针也就相当于定义了一个完整的链表。为了程序的可读性，只有头指针
    的类型为LinkList，后面的指向某结点的指针都记为*LNode。)
    一条链表其实可以如此形象的表示：
        LinkList->LNode-LNode-LNode-LNode-LNode-LNode-LNode-LNode-LNode...

    在理清如上概念后，现在定义一个链表（头指针）为LinkList L;
    当L有定义时，值要么为1）NULL，表示一个空表
                         2）第一个结点的地址，即L为链表的头指针
*/

// 单链表的创建的两种方法
/* 1.头插结点法：在链表的头部插入结点建立单链表 （比较简单）
    L->25
    L->45->25
    L->18->45->25
    即不断地将头指针指向新结点，用新结点的next指针指向原来的第一个结点
*/
LinkList Creat_LinkList1(){
    LinkList L = NULL;          // 定义一个空表L
    LNode *s;                    // 重复利用，建立结点指针，用来给结点开辟内存空间
    int x;                      // 重复利用，将x的值赋给新结点的data域
    cin >> x;
    while (x != 10)             // 这里的10相当于一个flag，即输入10时，终止这个链表的创建
    {
        // 用结点指针s为新结点开辟存储空间
        s = (LNode *)malloc(sizeof(LNode));

        s->data = x;
        // 下面两行代码用于将结点s插入到链表头部
        s->next = L;
        L = s;
        cin >> x;
    }
    return L;
}
/*2.尾插结点法：在链表的尾部插入结点建立单链表 （读入数据元素的顺序与生成链表中元素的顺序相一致）
   每次将新结点插入到链表的尾部，所以要加入一个“尾指针”
   L->29<-r
   L->29->76<-r
   L->29->76->18<-r
   L->29->76->18->45<-r
   初始状态的时候，将头指针L和尾指针r设为NULL

   “第一个结点”的问题：
   尾插结点中，第一个结点的处理比较特殊。他加入时链表为空，没有直接的前驱结点；而他的地址就是整个链表的地址，

*/
LinkList Creat_LinkList2(){
    LinkList L = NULL;   // 创建一个空链表，头指针L置为空
    LNode *r = NULL;     // 设置尾指针，因为目前是空表，所以先将尾指针置为空。只用其指针域，不用其数据域。

    LNode *s = NULL;     // 重复利用，用来不断地创建新的结点
    int x;               // 重复利用，用来给新的结点赋值
    cin >> x;
    while(x != 10){
        // 用结点指针s为新结点开辟存储空间
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        if(L == NULL)     // 第一个结点的处理，头指针L指向第一个结点
            L = s;
        else              // 其他结点的处理，尾指针的指向新结点
            r->next = s;
        r = s;            // r指向新的尾结点
        cout << x;
    }
    if(r != NULL)         // 对于非空表，最后结点指针域置空
        r->next = NULL;
    return L;
}
int main()
{

    return 0;
}
