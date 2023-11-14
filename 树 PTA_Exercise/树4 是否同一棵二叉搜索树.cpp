//
// Created by ByteDance on 2023/11/14.
//
#include<iostream>
#include<iostream>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(nullptr),right(nullptr){};
};

TreeNode* Insert(TreeNode* root, int x){
    // 为空 创建一个新树
    if(!root){
        root = new TreeNode;
        root->data = x;
    }
    else{
        if(x<root->data){
            root->left = Insert(root->left,x);
        }
        else if(x>root->data){
            root->right = Insert(root->right,x);
        }
    }
    return root;
}
// 用来记录是否相同的
void preOrderTravelsal(TreeNode* root,string& s){
    if(root){
        s+=root->data+'0';
        preOrderTravelsal(root->left,s);
        preOrderTravelsal(root->right,s);
    }
}

int main(){
    while(true){
        int n,l;
        int a[10];
        int tmp;
        TreeNode* t=nullptr;
        string ans;
        cin>>n>>l;
        if(n == 0)
            return 0;
        for(int i=0;i<n;i++){
            cin>>tmp;
            t = Insert(t,tmp);
        }
        preOrderTravelsal(t,ans);

        for(int i=0;i<l;i++){
            TreeNode* t=nullptr;
            string str;
            for(int j=0;j<n;j++){
                cin>>tmp;
                t = Insert(t,tmp);
            }
            preOrderTravelsal(t,str);
            if(str == ans){
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
    }
}