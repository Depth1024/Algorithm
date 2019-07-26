#include <cstdio>
#include <stack>  // 使用stack前须导入
#include <queue>  // 使用queue前须导入
/* 首先来看 Stack 栈
 两种操作：push & pop
 push ：将新元素压入栈顶
 pop ： 取出栈顶元素
 综上，栈的特征为 ==>> LIFO ：last in first out 后进先出的结构
 
 c++库提供的三种操作：
 1.stack::pop 移除最顶端的数据
 2.stack::top （又称peek，瞥一眼、窥一眼的意思）访问最顶端的数据
 3.stack::push 将新元素压入栈顶
 */
// 使用stack的案例：
// 使用前一定要先导入 stack 头文件
int stackTest(){
    stack<int> s;               // 声明一个存储类型为 int 的栈，命名为s
    s.push(1);                  // {} -> {1}
    s.push(2);                  // {1} -> {1,2}
    s.push(3);                  // {1,2} -> {1,2,3}
    printf("%d\n",s.top());     // 访问栈顶元素 3
    s.pop();                    // 移除栈顶元素3  {1,2,3} -> {1,2}
    printf("%d\n",s.top());     // 2
    s.pop();                    // {1,2} -> {1}
    printf("%d\n",s.top());     // 1
    s.pop();                    // {1} -> {}
    return 0
}

/*再来看 Queue 队列
 与栈一样，同样有两种操作push和pop
 push ： 将新元素压入栈顶
 pop ： 取出栈底元素
 综上，队列的特征为 ==>> FIFO ： first in first out
 
 c++库提供的三种操作：
 1.queue::pop 移除最底部的元素
 2.queue::front 访问最底部的元素
 3.queue::push 将新元素压入栈顶
 */
// 使用queue的案例：
// 使用前一定要先导入 queue 头文件
int queueTest(){
    queue<int> q;                   // 声明一个int类型的队列 命名为q
    q.push(1);                      // {} -> {1}
    q.push(2);                      // {1} -> {1,2}
    q.push(3);                      // {1,2} -> {1,2,3}
    printf("%d\n",q.front());       // 访问栈底元素1 并打印   1
    q.pop();                        // {1,2,3} -> {2,3}
    printf("%d\n",q.front());       // 2
    q.pop();                        // {2,3} -> {3}
    printf("%d\n",q.front());       // 3
    q.pop();                        // {3} -> {}
    return 0;
}

int main(){
    
}
