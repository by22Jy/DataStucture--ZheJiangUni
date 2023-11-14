//
// Created by ByteDance on 2023/11/14.
// 建立avl树
#include<iostream>
using namespace std;
class AvlTree{
public:
    int data;
    AvlTree* left;
    AvlTree* right;
    int height;
    AvlTree():data(0),left(nullptr),right(nullptr),height(0){};
};

int GetHeight(AvlTree* A){
    if(A == nullptr)
        return 0;
    return max(GetHeight(A->left), GetHeight(A->right))+1;
}

// 左单旋
AvlTree* SingleLeftRotation(AvlTree* A){
    AvlTree* B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = GetHeight(A);
    B->height = GetHeight(B);
    return B;
}

//右单旋
AvlTree* SingleRightRotation(AvlTree* A){
    AvlTree* B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = GetHeight(A);
    B->height = GetHeight(B);
    return B;
}

// 左-右双旋
AvlTree* DoubleLeftRightRotation(AvlTree* A){
    // A必须有一个左节点B B必须有一个右节点C
    A->left = SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}

// 右-左双旋
AvlTree* DoubleRightLeftRotation(AvlTree* A){
    // A必须有一个右节点B B必须有一个左节点C
    A->right = SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}

// 插入并在过程中形成自平衡的搜索二叉树
AvlTree* Insert(AvlTree* t,int x){
    if(!t){
        t = new AvlTree;
        t->data = x;
        t->left = t->right = nullptr;
    }

    else if(x<t->data){
        // 向左子树插入 可能用到左自旋 或 左-右双旋
        t->left = Insert(t->left,x);
            if(GetHeight(t->left) - GetHeight(t->right) == 2){
                if(x<t->left->data)
                    t = SingleLeftRotation(t);
                else
                    t = DoubleLeftRightRotation(t);
            }
        }
    else if(x>t->data){
        // 向右子树插入 可能用到右自旋 或 右-左双旋
        t->right = Insert(t->right,x);
        if(GetHeight(t->right) - GetHeight(t->left) == 2){
            if(x>t->right->data)
                t = SingleRightRotation(t);
            else
                t = DoubleRightLeftRotation(t);
        }
    }
    t->height = GetHeight(t);
    return t;
}

int main(){
    AvlTree* root = nullptr;
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        root = Insert(root,tmp);
    }
    cout<<root->data<<endl;
}


