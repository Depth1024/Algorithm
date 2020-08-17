#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n;
vector<int> preorder,inorder,postorder;
// 定义二叉树的结点
struct node{
    int data;
    node* lchild;
    node* rchild;
};
// 重建二叉树
node* create(int preL,int preR,int inL,int inR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = preorder[preL];
    //找到root在中序序列中的位置k
    int k;
    for(k = inL;k<inR;k++){
        if(inorder[k] == root->data)
            break;
    }
    int leftNum = k - inL;
    // 处理左子树
    root->lchild = create(preL+1,preL+leftNum,inL,k-1);
    // 处理右子树
    root->rchild = create(preL+leftNum+1,preR,k+1,inR);

    // 返回根结点
    return root;
}
// 后序遍历
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    postorder.push_back(root->data);
}

int main(){
    scanf("%d",&n);
    stack<int> s; // 用于中序遍历的stack
    string str;
    int temp;
    for(int i=0;i<2*n;i++){
        cin >> str;
        // 压栈是按照先序压栈的
        if(str == "Push"){
            scanf("%d",&temp);
            preorder.push_back(temp);
            s.push(temp);
        //出栈是按照中序出栈的
        } else if(str == "Pop"){
            // 先保存栈顶元素
            inorder.push_back(s.top());
            //printf("%d",s.top());
            s.pop();
        }
    }
    // 此时，先序序列preorder和中序序列inorder已经排列完成，下面重建二叉树、后序遍历即可
    node* root = create(0,n-1,0,n-1);
    postOrder(root);
    for(int i=0;i<n-1;i++){
        printf("%d ",postorder[i]);
    }
    printf("%d",postorder[n-1]);
    return 0;
}
