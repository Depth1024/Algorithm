#include <iostream>

using namespace std;
// 递归

// 利用递归计算阶乘 n! = n * （n - 1）!
int fact(int n){
    if(n == 0)   // 终止条件。 每个递归函数都必须有一个终止条件
        return 1;
    else
        n * fact(n-1); // n! ->>>  fact(n) = n * fact(n-1)  <<<- n * (n-1)!
}

// 递归 斐波那契数列 a0 = 0, a1 = 1, an = a<n-1> + a<n-2>
int fib(int n){
    if(n <= 1) // a0 = 0,a1 = 1
        return n;
    else
        return fib(n-1) + fib(n-2);  // fib(n) = fib(n-1) + fib(n-2)
}
/*
 总结一下递归，大致有两个关键步骤：
 1.找到临界条件（终止条件）
 2.找到相邻项之间的关系，这部分通常在题干中就会给出。
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

