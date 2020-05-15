 // B1046 划拳
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 规则：两人划拳，并各喊一个数；若“划” = “甲喊的数” + “乙喊的数”，则赢，另一个喝酒

int main(){
    int aShout,bShout,aHand,bHand;// 几个int类型的数  甲喊、乙喊；甲划、乙划    均<= 100
    int n;// 划拳的次数
    int aDrink = 0,bDrink = 0; // 甲喝的杯数、乙喝的杯数
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&aShout,&aHand,&bShout,&bHand);
        if(aHand == aShout + bShout && bHand != aShout + bShout){
            bDrink ++;
           // printf("乙喝酒\n");
        }else if(aHand != aShout + bShout && bHand == aShout + bShout){
            aDrink ++;
            //printf("甲喝酒\n");
        }
    }
    printf("%d %d",aDrink,bDrink);
    return 0;
}



