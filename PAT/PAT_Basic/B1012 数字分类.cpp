// B1012 数字分类
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 1000

int main(){
    int a[N]={},n;
    int a1[N]={},a2[N]={},a3[N]={},a4[N]={},a5[N]={};  // 设置5个子数组，分别存储5类数
    int a1num=0,a2num=0,a3num=0,a4num=0,a5num=0;      // 每个子数组的元素个数
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        switch(a[i] % 5){
            case 0:
                a1[a1num] = a[i];
                a1num++;
                break;
            case 1:
                a2[a2num] = a[i];
                a2num++;
                break;
            case 2:
                a3[a3num] = a[i];
                a3num++;
                break;
            case 3:
                a4[a4num] = a[i];
                a4num++;
                break;
            case 4:
                a5[a5num] = a[i];
                a5num++;
                break;
            default:
                break;
        }
    }

    //A1 = 能被 5 整除的数字中所有偶数的和；
    int A1 = 0;
        for(int i=0;i<a1num;i++){
            if(a1[i] % 2 == 0){  // 如果是偶数
                A1 += a1[i];
            }
        }
    if(A1 > 0){

        printf("%d ",A1);
    }else{
        printf("N ");
    }
    //A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n4⋯；
    if(a2num > 0){
        int A2 = 0;
        for(int i=0;i<a2num;i++){
            if(i % 2 == 0)
                A2 += a2[i];
            else
                A2 -= a2[i];
        }
        printf("%d ",A2);
    }else{
        printf("N ");
    }
    //A3 = 被 5 除后余 2 的数字的个数；
    if(a3num > 0){
        int A3 = a3num;
        printf("%d ",A3);
    }else{
        printf("N ");
    }
    //A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
    if(a4num > 0){
        double a4Sum = 0;
        for(int i=0;i<a4num;i++){
            a4Sum += a4[i];
        }
        double A4 = a4Sum / a4num;
        printf("%.1f ",A4);
    }else{
        printf("N ");
    }
    //A5 = 被 5 除后余 4 的数字中最大数字。
    if(a5num > 0){
        int A5=a5[0];
        for(int i=1;i<a5num;i++){
            if(A5 < a5[i])
                A5 = a5[i];
        }
        printf("%d",A5);
    }else{
        printf("N");
    }

    return 0;
}



