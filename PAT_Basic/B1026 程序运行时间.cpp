// B1026程序运行时间
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define CLK_TCK 100 // 每秒钟有100个clock_tick(时钟打点)


/* 几种取整类型回顾
   1.四舍五入用round函数    round(double x);
   2.向下取整用floor(double x)   地板floor
   3.向上取整用ceil(double x)    天花板ceil
*/
int main(){
    int c1,c2;  // 输入两个打点时刻
    scanf("%d %d",&c1,&c2);
    // 10^9以内都可以用int
    int t = round((double)(c2 - c1) / CLK_TCK);  // 运行时长 = (c2 - c1)/CLK_TCK  单位 秒
    // 运行时长格式化  1h = 60min = 3600s
    int h = 0,m = 0,s = 0;
    while(t >= 3600){
        t -= 3600;
        h++;
    }
    while(t >= 60){
        t -= 60;
        m++;
    }
    s = t;
    printf("%02d:%02d:%02d",h,m,s);
    /* 格式化输出的地方printf
        %md 补空格右对齐
        %0md 补0右对齐
        %.mf 浮点数保留m位小数输出 （四舍六入五成双）
    */
    return 0;
}



