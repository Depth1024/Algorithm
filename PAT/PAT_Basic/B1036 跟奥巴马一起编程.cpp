#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;// n=>�����α߳�
    char c;// c=>��������αߵ���ĸ
    int row,col; // ���� ����     ���� = (���� / 2 ����������)

    scanf("%d %c",&n,&c);
    col = n;
    // ���� = (���� / 2 ����������)
    if(col % 2 == 0)
        row = col / 2;
    else
        row = (col + 1) / 2;

    for(int i=1;i <= row;i++){
        if(i == 1 || i == row){
            for(int j=1;j <= col;j++){
                printf("%c",c);
            }
        }else{
            printf("%c",c);
            for(int j=2;j <= col-1;j++){
                printf(" ");
            }
            printf("%c",c);
        }
        printf("\n");
    }


    return 0;
}
