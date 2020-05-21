// A1025 - PAT Ranking
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// 输入量N*K的最大值
#define MAXSIZE 40000
//registration_number final_rank location_number local_rank
struct student{
    char id[14];  // registration_number
    int score;
    int final_rank;
    int loc_number;  // 组号
    int loc_rank;
}stu[MAXSIZE];// 用一维数组代替二维数组便于寻址

// 自定义cmp函数————二级排序，分高在前，分同则注册号小的在前
bool cmp(student a,student b){
    if(a.score != b.score)
        return a.score>b.score;
    else
        return strcmp(a.id,b.id) < 0;
}

int main()
{
    int n,k;
    int num=0;  // 记录输入的元素总个数
    scanf("%d",&n);
    for(int i=0;i<n;i++){  // 从0开始循环，loc_number=i+1
        scanf("%d",&k);
        // 输入注册号&id
        for(int j=0;j<k;j++){
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].loc_number = i+1;// 组号
            num++;  // 每输入一次，num+1，用于寻址
        }
        // 组内排序
        sort(stu+num-k,stu+num,cmp);
        // 组内排名
        stu[num-k].loc_rank = 1;
        for(int j=num-k+1;j<num;j++){
            if(stu[j].score == stu[j-1].score)
                stu[j].loc_rank = stu[j-1].loc_rank;
            else
                stu[j].loc_rank = j-(num-k)+1;
        }
    }
    // 总排序
    sort(stu,stu+num,cmp);
    // 总排名
    printf("%d\n",num);
    stu[0].final_rank = 1;
    printf("%s %d %d %d\n",stu[0].id,stu[0].final_rank,stu[0].loc_number,stu[0].loc_rank);
    for(int i=1;i<num;i++){
        if(stu[i].score == stu[i-1].score)
                stu[i].final_rank = stu[i-1].final_rank;
            else
                stu[i].final_rank = i+1;
        printf("%s %d %d %d\n",stu[i].id,stu[i].final_rank,stu[i].loc_number,stu[i].loc_rank);
    }
    return 0;
}


