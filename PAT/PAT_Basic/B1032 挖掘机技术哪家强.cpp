#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000 // ���ò������������� 10^5

int main(){
    int n; // ��������
    int scoreMax = 0;  // ����ѧУ����ܳɼ������ֵ
    int maxSchoolNum = 0;   // �������ܳɼ���ѧУ���

    int schoolNum_temp;  // ѧУ��� ���ڴӼ�������ʱ�ݴ�
    int score_temp;      // ������Ա�ĳɼ������ڴӼ�������ʱ�ݴ�

    int score[N+1] = {};  // ÿ��ѧУ���ܳɼ�
    /*
    ���������������ֵ����Ϊ0�����������ַ���
    1��    {0}
    2��    {}
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
