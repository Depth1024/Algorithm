#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// 先谈一谈几种特殊的链表（循环链表、双向链表）
// 一、循环链表
/*
 1.循环链表的特点：
    将链表头指针置入该链表最后一个结点的指针域。(判断指针是否为NULL变为判断是否是头指针)
 2.循环链表中的遍历：
    对于单链表来说，只能从头结点开始遍历整个链表；而对于循环链表来说，则可以从表中任意一个结点
 开始遍历整个链表。因为它舍弃了“头指针”，改用了一个指向尾结点的“R指针”的链表标识方式，可以提高
 链表操作效率。
    以两个单循环链表H1、H2的链接操作来说。如果用头指针标识，那么要从头指针开始一个节点一个节点
 地遍历到尾结点，假设一共有n个结点，那么用头指针标识算法的时间复杂度为O(n);而如果使用尾指针R1、R2
 来标识，那么可以直接找到尾结点，从而使得时间复杂度为O(n).
 
 p = R1->next;        // 保存R1的头结点指针（R1->next）
 R1->next = R2->next->next;  // 头尾相连
 free(R2->next);    // 释放第二个循环链表的头结点
 R2->next = p;      // 组成循环链表
 */

int main(){
    
}
