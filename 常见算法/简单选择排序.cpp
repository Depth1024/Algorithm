#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 简单选择排序
// (1) ! 4 3 2 1* 2 6       找到a[0]-a[5]最小的数，与a[0]互换
// (2) 1 ! 4 3 2* 2 6       找到a[1]-a[5]最小的数，与a[1]互换
// (3) 1 2 ! 4 3 2* 6       找到a[2]-a[5]最小的数，与a[2]互换
// (4) 1 2 2 ! 4 3* 6       找到a[3]-a[5]最小的数，与a[3]互换
// (5) 1 2 2 3 ! 4* 6       找到a[4]-a[5]最小的数，与a[4]互换
// (6) 1 2 2 3 4 ! 6*       找到a[5]-a[5]最小的数，与a[5]互换=================这一步可以省略掉
// 最终结果：1 2 2 3 4 6

void easySelectSort(int a[],int n){  // 输入数组和数组元素个数
    for(int i=0;i<n;i++){ // i从0-n枚举

        // 先默认a[i]为最小值，当发现有元素比a[i]小的时候，通过换下标的方式进行替换
        int k = i;
        for(int j=i;j<n;j++){  // j从i-n枚举,寻找是否存在元素<a[i]
            // 如果有，替换下标
            if(a[k] > a[j])
                k = j;
        }
        // 进行交换
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

int main(){
    int a[10]; //定义一个数组 a[]
    int n; // 数组元素个数n
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    easySelectSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}

