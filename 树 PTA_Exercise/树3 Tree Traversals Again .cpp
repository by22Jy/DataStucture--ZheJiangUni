// created by wjy 2023/11/13
// 难点在于如何根据题目要求输入的类似中序遍历来建树
// 如果是push 检查当前栈的top是否具有左右节点
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class TreeNode{
public:
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(""),left(NULL),right(NULL){}
};

TreeNode* CreateTree(){
    stack<TreeNode*> s;

    int n;
    string str;
    cin>>n;
    cin.ignore();

    // 先把跟节点处理了 方便后续处理
    getline(cin,str);
    string value = str.substr(5);
    TreeNode* node = new TreeNode;
    TreeNode* root = node;
    node->data = value;
    s.push(node);
    for(int i=1;i<2*n;i++){
        getline(cin,str);
        if(str == "Pop"){
            node = s.top();
            s.pop();
        }
        else{
            value = str.substr(5);
            TreeNode* tmp = new TreeNode;
            tmp->data = value;
            if(node->left == NULL){
                node->left = tmp;
                node = node->left;
            }
            else{
                node->right = tmp;
                node = node->right;
            }
            s.push(tmp);
        }
    }
    return root;
}

void postOrderTravelsal(TreeNode* root,bool& flag){
    if(root) {
        postOrderTravelsal(root->left,flag);
        postOrderTravelsal(root->right,flag);
        if(!flag){
            flag = true;
        }
        else
            cout<<' ';
        cout << root->data; // 输出节点值
    }
}

int main()
{
    TreeNode* t = CreateTree();
    bool flag = false;
    postOrderTravelsal(t,flag);
}