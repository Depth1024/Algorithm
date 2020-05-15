#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int counter = 0; // 设置一个计数器，用于记录步数
    scanf("%d",&n);
    // 当n != 1时，持续循环
    while(n != 1){
        counter ++;
        // 判断奇偶
        if(n % 2 == 0){   // 偶数
            n /= 2;
        }else if(n % 2 == 1){  // 奇数
            n = (3*n + 1) / 2;
        }
    }
    printf("%d",counter);
    return 0;
}
