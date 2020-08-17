#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010   // 最大月饼种类数

struct Mooncake{
    double storage;
    double totalPrice;// 总价
    double price; // 单价
}mooncake[MAXN];

bool cmp(Mooncake a,Mooncake b);

int main()
{
    int n;
    double d; // n种类数；d市场需求总量
    scanf("%d%lf",&n,&d);
    // 输入每种月饼的库存量
    for(int i=0;i<n;i++){
        scanf("%lf",&mooncake[i].storage);
    }
    // 输入每种月饼的总价，并算出单价
    for(int i=0;i<n;i++){
        scanf("%lf",&mooncake[i].totalPrice);
        mooncake[i].price = mooncake[i].totalPrice / mooncake[i].storage;
    }
    // 根据单价排序
    sort(mooncake,mooncake+n,cmp);
    // 算最大利润
    int j=0;
    double profit=0;
    while(d >= mooncake[j].storage){
        d -= mooncake[j].storage;
        profit += mooncake[j].totalPrice;
        j++;
    }
    profit += d * mooncake[j].price;

    printf("%.2f",profit);
    return 0;
}
bool cmp(Mooncake a,Mooncake b){
    return a.price > b.price;
}