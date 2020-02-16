#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 直接插入排序
void insertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=0;
        // 一直比较到第一次a[i] < a[j]的时候，说明找到合适的位置了
        while(a[i] > a[j]){
            j++;
        }
        int temp = a[i];  // 存一下a[i]的值
        // 开始乾坤大挪移
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
