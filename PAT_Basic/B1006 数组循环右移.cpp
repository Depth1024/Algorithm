// B1008 ����ѭ����������
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100
int main(){
    int n,m;  // n����ʵ�ʳ���   m ����λ��
    int a[N]={},c1[N]={},c2[N]={};
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        int temp = a[n-1];
        for(int j=n-1;j>0;j--){
            a[j] = a[j-1];
        }
        a[0] = temp;
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[n-1]);
    return 0;
}



