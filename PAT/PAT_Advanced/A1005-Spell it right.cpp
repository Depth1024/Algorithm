#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
// 用栈来存储N
struct BigNum{
    char data[MAXSIZE];
    int top;
}N;

int pop(BigNum &a){
    char c;
    // 出栈前，判栈空
    if(a.top >= 0){
        c = a.data[a.top];
        a.top--;
    }
    int i= c - 48; // ascll码中“数字-48”为与其本身对应的ascll码值
    return i;
}

int main()
{
    // 初始化栈
    N.top = -1;
    // 输入非负整数N，并根据N的长度更改栈顶指针top
    scanf("%s",N.data);
    N.top = strlen(N.data) - 1;

    int sum = 0;
    int len = strlen(N.data);
    for(int i=0;i<len;i++){
        sum += pop(N);
    }

    if(sum == 0){
        printf("zero");
    }else{
        int result[5];
        int result_len=0;
        while(sum != 0){
            result[result_len] = sum % 10;
            result_len++;
            sum /= 10;
        }
        for(int i=result_len-1 ;i>=0;i--){
            switch(result[i]){
                case 0:
                    printf("zero");
                    break;
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
            }
            if(i > 0)
                printf(" ");
        }
    }


    return 0;
}


