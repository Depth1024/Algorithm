#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n,postorder[maxn],inorder[maxn],layer[maxn];

// 定义二叉树的结点
struct node{
    int data;
    node* lchild;
    node* rchild;
};
// 重建二叉树
node* create(int postL,int postR,int inL,int inR){
    if(postR < postL){
        return NULL;
    }
    node* root = new node;
    root->data = postorder[postR]; // 后序遍历，最右边的为root
    // 在中序遍历中找根节点
    int k;
    for(k=inL;k<inR;k++){
        if(inorder[k] == root->data){
            break;
        }
    }
    /*
     * 坑1：不能想当然把k和rightNum弄混！！！！！
     *
     * */
    // 此时，k为root在中序遍历中的序号，小于k为左子树，大于k为右子树
    // 由此计算出左子树、右子树的结点数
    int rightNum = inR - k;

    // 处理右子树
    root->rchild = create(postR-rightNum,postR-1,k+1,inR);
    // 处理左子树
    root->lchild = create(postL,postR-rightNum-1,inL,k-1);

    return root;
}
// 层序遍历二叉树
void BFS(node* root){
    int acc=0;
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* top = new node;
        top = q.front();
        q.pop();
        layer[acc++] = top->data;
        /*
         * 坑2：
         * 一定要先判断左子树、右子树是否为空，非空才能入队！！！
         *
         * */
        if(top->lchild != NULL) q.push(top->lchild);
        if(top->rchild != NULL) q.push(top->rchild);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&postorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    node* root = create(0,n-1,0,n-1);
    BFS(root);
    for(int i=0;i<n-1;i++){
        printf("%d ",layer[i]);
    }
    printf("%d",layer[n-1]);
    return 0;
}
