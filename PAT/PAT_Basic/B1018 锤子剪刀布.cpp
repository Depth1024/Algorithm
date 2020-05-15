// B1018 锤子剪刀布
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000  // 交手次数的最大值


int main(){
    int n;  // 双方交手的次数
    scanf("%d",&n);

    char a[N],b[N];   // C锤子 J剪刀 B布    注意大写
    int a_result[3]={0},b_result[3]={0}; // 用来统计比赛结果  规定 [0]输  [1]平  [2]赢
    int a_gesture[3]={0},b_gesture[3]={0}; // 用来统计赢时的手势 0-B 1-C 2-J
    for(int i=0;i<n;i++){
        scanf(" %c %c",&a[i],&b[i]);
        
        /*
        这个地方要复习一下%c的输入，%c是可以读入空格&\n的。
        上面使用scanf输入了n，并用\n表示输入完成，这个\n就留在了 输入缓冲池 中。
        包括for循环中每一次的scanf都会残留一个\n。
        
        解决方法：在第一个%c前加一个空格==>  scanf(" %c %c",&a,&b);
        */
        
        switch(a[i]){
            case 'C':
                if(b[i] == 'C'){ //平
                    a_result[1]++;
                    b_result[1]++;
                }else if(b[i] == 'J'){ // a赢b输
                    a_result[2]++;
                    a_gesture[1]++;
                    b_result[0]++;
                }else if(b[i] == 'B'){  // a输b赢
                    a_result[0]++;
                    b_result[2]++;
                    b_gesture[0]++;
                }
                break;
            case 'J':
                if(b[i] == 'C'){  // a输b赢
                    a_result[0]++;
                    b_result[2]++;
                    b_gesture[1]++;
                }else if(b[i] == 'J'){  // 平
                    a_result[1]++;
                    b_result[1]++;
                }else if(b[i] == 'B'){ // a赢b输
                    a_result[2]++;
                    a_gesture[2]++;
                    b_result[0]++;
                }
                break;
            case 'B':
                if(b[i] == 'C'){ // a赢b输
                    a_result[2]++;
                    a_gesture[0]++;
                    b_result[0]++;
                }else if(b[i] == 'J'){ // a输b赢
                    a_result[0]++;
                    b_result[2]++;
                    b_gesture[2]++;
                }else if(b[i] == 'B'){ // 平
                    a_result[1]++;
                    b_result[1]++;
                }
                break;
            //default:
             //   break;
        }
    }

    int a_max = 0, b_max = 0;
    for(int i=1;i<3;i++){
        if(a_gesture[i] > a_gesture[a_max])
            a_max = i;
        if(b_gesture[i] > b_gesture[b_max])
            b_max = i;
    }
    char gesture[3]={'B','C','J'};
    printf("%d %d %d\n",a_result[2],a_result[1],a_result[0]);
    printf("%d %d %d\n",b_result[2],b_result[1],b_result[0]);
    printf("%c %c",gesture[a_max],gesture[b_max]);
    return 0;
}



