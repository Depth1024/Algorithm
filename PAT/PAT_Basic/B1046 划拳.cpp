 // B1046 ��ȭ
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// �������˻�ȭ��������һ�������������� = ���׺������� + ���Һ�����������Ӯ����һ���Ⱦ�

int main(){
    int aShout,bShout,aHand,bHand;// ����int���͵���  �׺����Һ����׻����һ�    ��<= 100
    int n;// ��ȭ�Ĵ���
    int aDrink = 0,bDrink = 0; // �׺ȵı������Һȵı���
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&aShout,&aHand,&bShout,&bHand);
        if(aHand == aShout + bShout && bHand != aShout + bShout){
            bDrink ++;
           // printf("�ҺȾ�\n");
        }else if(aHand != aShout + bShout && bHand == aShout + bShout){
            aDrink ++;
            //printf("�׺Ⱦ�\n");
        }
    }
    printf("%d %d",aDrink,bDrink);
    return 0;
}



