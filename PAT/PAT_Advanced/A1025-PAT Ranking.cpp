// A1025 - PAT Ranking
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// ������N*K�����ֵ
#define MAXSIZE 40000
//registration_number final_rank location_number local_rank
struct student{
    char id[14];  // registration_number
    int score;
    int final_rank;
    int loc_number;  // ���
    int loc_rank;
}stu[MAXSIZE];// ��һά��������ά�������Ѱַ

// �Զ���cmp�������������������򣬷ָ���ǰ����ͬ��ע���С����ǰ
bool cmp(student a,student b){
    if(a.score != b.score)
        return a.score>b.score;
    else
        return strcmp(a.id,b.id) < 0;
}

int main()
{
    int n,k;
    int num=0;  // ��¼�����Ԫ���ܸ���
    scanf("%d",&n);
    for(int i=0;i<n;i++){  // ��0��ʼѭ����loc_number=i+1
        scanf("%d",&k);
        // ����ע���&id
        for(int j=0;j<k;j++){
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].loc_number = i+1;// ���
            num++;  // ÿ����һ�Σ�num+1������Ѱַ
        }
        // ��������
        sort(stu+num-k,stu+num,cmp);
        // ��������
        stu[num-k].loc_rank = 1;
        for(int j=num-k+1;j<num;j++){
            if(stu[j].score == stu[j-1].score)
                stu[j].loc_rank = stu[j-1].loc_rank;
            else
                stu[j].loc_rank = j-(num-k)+1;
        }
    }
    // ������
    sort(stu,stu+num,cmp);
    // ������
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


