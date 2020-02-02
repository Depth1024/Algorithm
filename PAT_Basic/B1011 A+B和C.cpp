#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; // 输入t个正整数
    long long a,b,c;
    /*
    int取值范围 [-2^31,2^31]    10^9以内或32bit整数
    long long 取值范围 [-2^63,2^63]     10^18以内或64bit整数
    */
    int result[10] = {0}; // 用于存放比较结果

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
