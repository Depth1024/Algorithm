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

// 一、单链表的创建的两种方法
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
   尾插结点法中，第一个结点的处理比较特殊。他加入时链表为空，没有直接的前驱结点；而他的地址就是整个链表的地址，
   这个地址需要放在链表的头指针中；而其他结点有前驱结点，他们的地址就放在前驱结点的指针域中。
 
   头结点：
    有时，为了运算方便，我们会为链表加入一个头结点，头结点的数据域毫无意义，指针域中存放的是第一个数据结点
    的地址（空表时为空）。

*/
LinkList Creat_LinkList2(){
    LinkList L = NULL;   // 头指针————创建一个空链表，头指针L置为空；当第一个结点加入链表中时，这个指针指向头结点的地址（即为整个链表的地址）
    LNode *r = NULL;     // 尾指针————设置尾指针，因为目前是空表，所以先将尾指针置为空。只用其指针域，不用其数据域。

    LNode *s = NULL;     // 结点指针————重复利用，用来不断地创建新的结点
    int x;               // 重复利用，用来给新的结点赋值
    cin >> x;
    while(x != 10){      // 10是一个flag值，用来终止输入
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

// 二、单链表求表长
/*
    求表长实际上是遍历整个链表，直到遍历到结点为空为止。那么就需要一个移动指针p（用来不断指向下一个结点）和一个计数器j（用来计算表长）。
 */
// 1.设L是带头结点的单链表
int Length_LinkList1(LinkList L){
    LNode *p = L;         // 移动指针，初始时和头指针L一样指向头结点，此时p->next则为第一个数据结点
    int j = 0;           // 计数器
    while (p->next) {
        p = p->next;
        j++;
    }
    return j;           // 返回表长
}
// 2.设L是不带头结点的单链表
int Length_LinkList2(LinkList L){
    LNode *p = L;
    int j = 0;
    while (p) {
        
    }
}
/*
 带头结点和不带头结点的辨析：
    带头结点和不带头结点的区别主要在于循环判断条件不一致。在这里只需要看第一个数据结点即可。
    带头结点：
            第一个数据结点位于头结点后一个，而p初始化时被赋予的值是头结点的地址，所以第一个数据结点
            即为p->next；
    不带头结点：
            第一个数据结点就在第一个位置，被头指针L指着。p初始化被赋予的值就是第一个数据结点的值，所以
            第一个数据结点就是p
 */

// 三、查找操作
/*1.按序查找（判断当前结点是否为链表的第i个结点）
    从第一个数据结点开始，不断判断当前结点是否为第i个结点。是的话就返回该结点的指针；不是的话就继续后一个。没有第i个结点时返回空。
 */
LNode *Get_LinkList(LinkList L,int i){
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j<i) {
        p = p-> next;
        j++;
    }
    if(j == i)
        return p;
    else
        return NULL;
}
/*2.按值查找
    从第一个结点开始，判断每一个结点的值是否等于x，如果是的话返回该结点的地址；否则继续后一个直到表结束；没有的话返回空。
 */
LNode *Locate_LinkList(LinkList L,int x){
    LNode *p = L;
    while (p->data != x && p != NULL) {
        p = p->next;
    }
    return p;
}

// 四、插入操作（用整型返回值表示操作是否成功）
/*插入三部曲：（前提是：找到前一个结点）
    1）新建结点 2）放数据 3）改指针
 
 算法思路：
    1）找到第i-1个结点，若存在，则继续，否则结束
    2）申请、填装新结点
    3）将新结点插入，结束
 */
int Insert_LinkList(LinkList L,int i,int x){      // 在单链表的第i个位置上插入值为x的元素
    LNode *p,*s;
    p = Get_LinkList(L,i-1);     // 调用按序查找，找到第i-1个结点（前提）
    if(p == NULL){                 //找到第i-1个结点后，判断其是否存在，若存在，则继续，否则停止。
        cout << "参数i错误：第i-1个结点不存在，不能插入" << endl;
        return 0;               // 返回0表示参数i错误
    }else{
        s = (LNode *)malloc(sizeof(LNode));     // 新建结点
    
        s->data = x;                            // 放数据
        
        s->next = p->next;                      // 改指针
        p->next = s;
        return 1;                       // 返回1表示操作完成
    }
}

// 五、单链表的删除操作（用整型返回值表示操作是否成功）
/*
 算法思路：（前提：第i-1结点的后继存在）
 1）找到第i-1个结点，若存在，则继续；否则结束。
 2）若第i-1个结点存在后继，即存在第i个结点，则继续
 3）删除第i个结点，结束。
 */
int Del_LinkList(LinkList L,int i){
    LNode *p,*s;
    p = Get_LinkList(L,i-1);            // 调用按序查找，找到第i-1个结点
    // 第i-1个结点不存在，返回-1
    if(p == NULL){
        cout << "第i-1个结点不存在" << endl;
        return -1;
    }
    // 第i个结点不存在，返回0
    else if(p->next == NULL){
        cout << "第i个结点不存在" << endl;
        return 0;
    }
    // 一切正常，返回1
    else{
        s = p->next;    // 用s临时存放第i-1个结点的地址
        p->next = s->next; // 改指针
        free(s); // 释放s
        return 1;
    }
}
int main()
{

    return 0;
}
