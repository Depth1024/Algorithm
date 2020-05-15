#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,da,db, pa=0,pb=0;
    int counta=0,countb=0; // 用于统计da、db在a、b中出现的次数
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

// 错误总结：一个低级错误=>  while中的判别条件写错，写成了 while(a%10 != 0)
// 写判别调节时一定要谨慎思考
