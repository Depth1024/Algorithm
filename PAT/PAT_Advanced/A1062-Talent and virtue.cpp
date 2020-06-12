// A1062 Talent and Virtue
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100000

struct People{
    int id;
    int virtueGrade;
    int talentGrade;
    int group; // 代表属于哪个类别  1-sage 2-nobleman 3-foolman 4-rest
}people[MAXSIZE];

bool cmpDivide(People a,People b){
    if(a.group != b.group)
        return a.group < b.group;
    else if((a.virtueGrade+a.talentGrade) != (b.virtueGrade+b.talentGrade))
        return (a.virtueGrade+a.talentGrade) > (b.virtueGrade+b.talentGrade);
    else if((a.virtueGrade+a.talentGrade)==(b.virtueGrade+b.talentGrade) && a.virtueGrade != b.virtueGrade)
        return a.virtueGrade > b.virtueGrade;
    else
        return a.id < b.id;
}

int main()
{
    int num=0;// 记录参与排名的总人数
    int n,l,h;
    scanf("%d %d %d",&n,&l,&h);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&people[i].id,&people[i].virtueGrade,&people[i].talentGrade);
        if(people[i].talentGrade >= l && people[i].virtueGrade >= l){

            num++;

            if(people[i].talentGrade >= h && people[i].virtueGrade >= h)
                people[i].group = 1; // 圣人sage
            else if(people[i].talentGrade < h && people[i].virtueGrade >=h)
                people[i].group = 2; // 君子nobleman
            else if(people[i].talentGrade < h && people[i].virtueGrade < h && people[i].virtueGrade >= people[i].talentGrade)
                people[i].group = 3; // 愚人foolman
            else
                people[i].group = 4; // rest
        }else{
            i--;
            n--;
        }
    }
    sort(people,people+n,cmpDivide);
    printf("%d\n",num);
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",people[i].id,people[i].virtueGrade,people[i].talentGrade);
    }

    return 0;
}


