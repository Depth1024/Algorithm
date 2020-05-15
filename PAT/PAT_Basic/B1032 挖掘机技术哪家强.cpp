#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000 // 设置参赛人数的上限 10^5

int main(){
    int n; // 参赛人数
    int scoreMax = 0;  // 设置学校获得总成绩的最高值
    int maxSchoolNum = 0;   // 获得最高总成绩的学校编号

    int schoolNum_temp;  // 学校编号 用于从键盘输入时暂存
    int score_temp;      // 参赛人员的成绩，用于从键盘输入时暂存

    int score[N+1] = {};  // 每个学校的总成绩
    /*
    如果想把整个数组的值都赋为0，有如下两种方法
    1）    {0}
    2）    {}
    */

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d",&schoolNum_temp,&score_temp);
        score[schoolNum_temp] += score_temp;
        if(score[schoolNum_temp] > scoreMax){
            scoreMax = score[schoolNum_temp];
            maxSchoolNum = schoolNum_temp;
        }
    }
    printf("%d %d",maxSchoolNum,scoreMax);
    return 0;
}
