/*
 ���Ա�˳��洢
                */
#include <iostream>
#include <bits/stdc++.h>
#define MAXSIZE 1000
// ��Ϊ��ͨ���ǿɱ�ģ�����Ҫ������������㹻���������һ�������������MAXSIZE�ͼ�¼���Ա�ʵ�ʳ��ȵı���last
using namespace std;

// ���涨��һ��˳���
typedef struct{
    int data[MAXSIZE]; // ����һ�������㹻�������
    int last; // ����һ���������洢������Ա�ĳ���Ϊlast+1
}SeqList;

// 1��˳���ĳ�ʼ����ֱ�ӽ������õ�˳����룩
SeqList *init_SeqList(SeqList *L){
    L = (SeqList *)malloc(sizeof(SeqList)); // Ϊ˳������洢�ռ�
    L->last = -1; // ��=last+1=0,��˽�last��Ϊ-1
    cout << "A SeqList has been Inited!" <<endl; // Ϊ����۲죬������ʱ��ӡ
    return L;
}
                // ����init_SeqList����,�����������
SeqList *init_SeqList(){
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList)); // Ϊ˳������洢�ռ�
    L->last = -1; // ��=last+1=0,��˽�last��Ϊ-1
    cout << "A SeqList has been Inited!" <<endl; // Ϊ����۲죬������ʱ��ӡ
    return L;
}

// 2��˳���Ĳ�������
/*
�����ڵ�i��λ�ò���һ����Ԫ�أ��жϱ����Ͳ���λ�õ���ȷ��֮��
1)��ai~an˳�������ƶ����ó���λ
2)��x����
3)�޸ı���last������ֵ����ʹ��ʼ��= last + 1
*/
int Insert_SeqList(SeqList *L,int i,int x){    // ������������һ��������һ��λ�á������ֵ��ʲô
    int j;
    // �����жϱ�������������������ٽ��в������,����-1
    if(L->last = MAXSIZE-1){
        cout << "FULL!" << endl;
        return -1;
    }
    // �жϲ���λ���Ƿ���ȷ
    if(i<1 || i>L->last+2){
        cout << "Wrong location!" << endl;
        return 0;
    }
    // ��ʽ��ʼ�������
    // 1��ai~an��������ƶ�
    for(j=L->last;j>=i-1;j--){
        L->data[j+1] = L->data[j];
    }
    // 2������x
    L->data[i-1] = x;
    // 3���޸ı�
    L->last++;
    return 1;
}

// 3��˳����ɾ������
/*
�����е�i��Ԫ�ش�˳�����ɾ�����жϱ�պ�ɾ��δ֪����ȷ��֮��
1����ai+1~anԪ��˳����ǰ�ƶ�
2���޸�lastָ�루�൱���޸ı���ʹ֮��ָ�����һ��Ԫ��
*/
int Delete_SeqList(SeqList *L,int i){
    int j;
    // �жϱ�������λ���Ƿ���ȷ
    if(i<1 || i>L->last+1){  // ���L->last = -1�Ļ�,i>0�����ж��˱��
        cout << "The first number doesn't exist." << endl;
        return 0;
    }
    // ��Ԫ��˳��ǰ��
    for(j=i;j<=L->last;j++){
        L->data[j-1] = L->data[j];
    }
    // �޸ı�
    L->last--;
    return 1; //ɾ���ɹ�
}

// 4��˳����еİ�ֵ����
int Loacation_SeqList(SeqList *L,int x){
    int i=0;
    while(i<=L->last && L->data[i] != x){
        i++;
    }
    if(i > L->last)
        return -1; // ����ʧ�ܣ�����-1
    else
        return i; // ���ҳɹ������ش洢λ��
}

int main()
{
    // ��һ�ֶ���˳���ķ�����ͨ���ṹ�����ʽ����
    // һ�㲻�����ַ�ʽ����Ϊ�������ݺܲ�����
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
    // �ڶ��ֶ���˳���ķ�����ͨ��ָ�뷽ʽ���� ����������������>>>�Ƚϳ���
    // ����˳���ĺ����������ǻ���ָ�붨��ķ�ʽ��ʵ�ֵ�
    SeqList *L2,*L3;
    // ˳���ĳ�ʼ��
    init_SeqList(L2); // ֱ�ӽ������õ�˳�����
    L3 = init_SeqList(); // �����������


    return 0;
}
