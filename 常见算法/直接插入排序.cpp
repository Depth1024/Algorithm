#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ֱ�Ӳ�������
void insertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=0;
        // һֱ�Ƚϵ���һ��a[i] < a[j]��ʱ��˵���ҵ����ʵ�λ����
        while(a[i] > a[j]){
            j++;
        }
        int temp = a[i];  // ��һ��a[i]��ֵ
        // ��ʼǬ����Ų��
        for(int t=i;t>j;t--){
            a[t] = a[t-1];
        }
        a[j] = temp;
    }
}

int main(){
    int a[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertSort(a,n);
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
    return 0;
}
