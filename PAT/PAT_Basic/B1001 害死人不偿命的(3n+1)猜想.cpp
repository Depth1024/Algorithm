#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int counter = 0; // ����һ�������������ڼ�¼����
    scanf("%d",&n);
    // ��n != 1ʱ������ѭ��
    while(n != 1){
        counter ++;
        // �ж���ż
        if(n % 2 == 0){   // ż��
            n /= 2;
        }else if(n % 2 == 1){  // ����
            n = (3*n + 1) / 2;
        }
    }
    printf("%d",counter);
    return 0;
}
