// B1026��������ʱ��
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define CLK_TCK 100 // ÿ������100��clock_tick(ʱ�Ӵ��)


/* ����ȡ�����ͻع�
   1.����������round����    round(double x);
   2.����ȡ����floor(double x)   �ذ�floor
   3.����ȡ����ceil(double x)    �컨��ceil
*/
int main(){
    int c1,c2;  // �����������ʱ��
    scanf("%d %d",&c1,&c2);
    // 10^9���ڶ�������int
    int t = round((double)(c2 - c1) / CLK_TCK);  // ����ʱ�� = (c2 - c1)/CLK_TCK  ��λ ��
    // ����ʱ����ʽ��  1h = 60min = 3600s
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
    /* ��ʽ������ĵط�printf
        %md ���ո��Ҷ���
        %0md ��0�Ҷ���
        %.mf ����������mλС����� �������������˫��
    */
    return 0;
}



