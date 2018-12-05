/*
 线性表顺序存储
                */
#include <iostream>
#include <bits/stdc++.h>
#define MAXSIZE 1000
// 因为表长通常是可变的，所以要求数组的容量足够大，因此设置一个数组最大容量MAXSIZE和记录线性表实际长度的变量last
using namespace std;

// 下面定义一个顺序表
typedef struct{
    int data[MAXSIZE]; // 定义一个容量足够大的数组
    int last; // 定义一个变量来存储这个线性表的长度为last+1
}SeqList;

// 1、顺序表的初始化（直接将声明好的顺序表传入）
SeqList *init_SeqList(SeqList *L){
    L = (SeqList *)malloc(sizeof(SeqList)); // 为顺序表分配存储空间
    L->last = -1; // 表长=last+1=0,因此将last置为-1
    cout << "A SeqList has been Inited!" <<endl; // 为方便观察，在运行时打印
    return L;
}
                // 重载init_SeqList方法,不带传入参数
SeqList *init_SeqList(){
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList)); // 为顺序表分配存储空间
    L->last = -1; // 表长=last+1=0,因此将last置为-1
    cout << "A SeqList has been Inited!" <<endl; // 为方便观察，在运行时打印
    return L;
}

// 2、顺序表的插入运算
/*
假设在第i个位置插入一个新元素（判断表满和插入位置的正确性之后）
1)将ai~an顺序向下移动，让出空位
2)将x插入
3)修改表长（last变量的值），使表长始终= last + 1
*/
int Insert_SeqList(SeqList *L,int i,int x){    // 三个参数：哪一个链表、哪一个位置、插入的值是什么
    int j;
    // 首先判断表满。如果表满，则不能再进行插入操作,返回-1
    if(L->last = MAXSIZE-1){
        cout << "FULL!" << endl;
        return -1;
    }
    // 判断插入位置是否正确
    if(i<1 || i>L->last+2){
        cout << "Wrong location!" << endl;
        return 0;
    }
    // 正式开始插入操作
    // 1、ai~an依次向后移动
    for(j=L->last;j>=i-1;j--){
        L->data[j+1] = L->data[j];
    }
    // 2、插入x
    L->data[i-1] = x;
    // 3、修改表长
    L->last++;
    return 1;
}

// 3、顺序表的删除运算
/*
将表中第i个元素从顺序表中删除（判断表空和删除未知的正确性之后）
1）将ai+1~an元素顺序向前移动
2）修改last指针（相当于修改表长）使之仍指向最后一个元素
*/
int Delete_SeqList(SeqList *L,int i){
    int j;
    // 判断表空与插入位置是否正确
    if(i<1 || i>L->last+1){  // 如果L->last = -1的话,i>0正好判断了表空
        cout << "The first number doesn't exist." << endl;
        return 0;
    }
    // 将元素顺序前移
    for(j=i;j<=L->last;j++){
        L->data[j-1] = L->data[j];
    }
    // 修改表长
    L->last--;
    return 1; //删除成功
}

// 4、顺序表中的按值查找
int Loacation_SeqList(SeqList *L,int x){
    int i=0;
    while(i<=L->last && L->data[i] != x){
        i++;
    }
    if(i > L->last)
        return -1; // 查找失败，返回-1
    else
        return i; // 查找成功，返回存储位置
}

int main()
{
    // 第一种定义顺序表的方法：通过结构体变量式定义
    // 一般不用这种方式，因为参数传递很不方便
    /*
    SeqList L1;
    L1.last = 10;
    for(int i=0;i<L1.last;i++){
        cin >> L1.data[i];
    }
    for(int i=0;i<L1.last;i++){
        cout << L1.data[i] << endl;
    }
    */
    // 第二种定义顺序表的方法：通过指针方式定义 ————————>>>比较常用
    // 所有顺序表的函数操作都是基于指针定义的方式来实现的
    SeqList *L2,*L3;
    // 顺序表的初始化
    init_SeqList(L2); // 直接将声明好的顺序表传入
    L3 = init_SeqList(); // 不带传入参数


    return 0;
}
