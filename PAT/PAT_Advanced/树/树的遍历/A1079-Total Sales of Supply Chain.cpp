

// 这个是用bfs做的，最后一个case点超时。过后自己尝试用dfs做



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
double p,r;
// 只有没有上线的那个结点才是root，所以设置一个flag数组，排除所有receive的，剩下那个就是root
bool flag[maxn] = {false}; // 用于找出根结点
double totalprice = 0; // 总价格


struct node{
    int data;
    int depth; // 该结点的深度
    vector<int> child;
};

double calculatePrice(int depth){
    double price=p;
    for(int i=0;i<depth;i++){
        price *= (1+r*0.01);
    }
    return price;
}

vector<node*> k;

// 遍历
void BFS(node* root){
    queue<node*> q;
    root->depth = 0;
    q.push(root);
    while (!q.empty()){
        node* now = q.front();
        // 如果ki是retail，就计算价值
        if(now->data == 0){
            totalprice += now->child[0] * calculatePrice(now->depth);
        }
        q.pop();
        if(now->data != 0){
            for(int i=0;i<now->child.size();i++){
                q.push(k[now->child[i]]);
                k[now->child[i]]->depth = now->depth+1;
            }
        }

    }
}


int main(){
    scanf("%d %lf %lf",&n,&p,&r);

    for(int i=0;i<n;i++){
        node* temp = new node;
        int t;
        scanf("%d",&temp->data);
        if(temp->data == 0){
            scanf("%d",&t);
            temp->child.push_back(t);
        } else{
            for(int j=0;j<temp->data;j++){
                scanf("%d",&t);
                // 把有上线的都设为true
                if(flag[t] == false){
                    flag[t] = true;
                }
                temp->child.push_back(t);
            }
        }
        k.push_back(temp);
    }
    // 找根结点序号
    int root_index; // 用于存放根结点序号

    for(int i=0;i<n;i++){
        if(flag[i] == false){
            root_index = i;
            break;
        }
    }
    //printf("%d",root_index);
    // 从根结点开始，层序遍历
    BFS(k[root_index]);
    printf("%.1f",totalprice);
    return 0;
}
