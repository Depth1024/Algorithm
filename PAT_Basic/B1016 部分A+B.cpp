#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,da,db, pa=0,pb=0;
    int counta=0,countb=0; // ����ͳ��da��db��a��b�г��ֵĴ���
    scanf("%d %d %d %d",&a,&da,&b,&db);

    while(a != 0){
        if(a % 10 == da){
            counta++;
            pa = pa*10 + da;
        }
        a /= 10;
    }
    while(b != 0){
        if(b % 10 == db){
            countb++;
            pb = pb*10 + db;
        }
        b /= 10;
    }
    printf("%d",pa+pb);
    return 0;
}

// �����ܽ᣺һ���ͼ�����=>  while�е��б�����д��д���� while(a%10 != 0)
// д�б����ʱһ��Ҫ����˼��
