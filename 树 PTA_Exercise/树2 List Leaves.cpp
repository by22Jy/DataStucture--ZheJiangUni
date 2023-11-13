// 树的广度优先遍历应用
#include<iostream>
#include<queue>
using namespace std;
int null=-1;
class TreeNode{
public:
    int data;
    int left;
    int right;
};
TreeNode t[10];

int ReadData(){
    int n;
    int root = 0;
    cin>>n;
    if(!n)
        return null;
    for(int i=0;i<n;i++){
        t[i].data=i;
        char left,right;
        cin>>left>>right;
        if(left == '-'){
            t[i].left = null;
        }
        else{
            t[i].left = left - '0';
            root -= t[i].left;
        }
        if(right == '-'){
            t[i].right = null;
        }
        else{
            t[i].right = right - '0';
            root -= t[i].right;
        }
        root += i;
    }
    return root;
}

void bfs(int root){
    queue<TreeNode> q;
    q.push(t[root]);
    bool flag = false;
    // 如果树为空 直接返回
    if(root == null){
        cout<<'-'<<endl;
        return;
    }

    while(q.size()){
        TreeNode tmp = q.front();
        q.pop();
        if(tmp.left == null && tmp.right == null){  // 如果为叶子结点就输出
            if(flag)
                cout<<" ";
            else
                flag = true;
            cout<<tmp.data;
        }
        if(tmp.left != null){
            q.push(t[tmp.left]);
        }
        if(tmp.right != null){
            q.push(t[tmp.right]);
        }

    }
}

int main()
{
    int root = ReadData();
    bfs(root);
}