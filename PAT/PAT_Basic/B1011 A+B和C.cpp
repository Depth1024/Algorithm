#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; // ����t��������
    long long a,b,c;
    /*
    intȡֵ��Χ [-2^31,2^31]    10^9���ڻ�32bit����
    long long ȡֵ��Χ [-2^63,2^63]     10^18���ڻ�64bit����
    */
    int result[10] = {0}; // ���ڴ�űȽϽ��

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if( (a+b) > c)
            result[i] = 1;
        else
            result[i] = 0;
    }
    for(int i=0;i<t;i++){
        if(result[i] == 1)
            printf("Case #%d: true\n",i+1);
        else
            printf("Case #%d: false\n",i+1);
    }

    return 0;
}
