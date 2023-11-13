#include<iostream>

#define null -1
using namespace std;

class TreeNode {
public:
    char data;
    int left;
    int right;
};

TreeNode T1[10], T2[10];

// 读入数据并返回根节点 这道题区别其他树的题 每个节点的索引不是顺序的 而是任意的
// 所以根节点不能直接取零 而需要处理
int ReadData(TreeNode *T) {
    int n;
    int root = 0;
    cin >> n;
    if (!n) {
        return null;
    }
    for (int i = 0; i < n; i++) {
        char value, left, right;
        cin >> value >> left >> right;
        T[i].data = value;
        if (left == '-') {
            T[i].left = null;
        } else {
            // 确定节点
            T[i].left = left - '0';
            root -= T[i].left;
        }
        if (right == '-') {
            T[i].right = null;
        } else {
            T[i].right = right - '0';
            root -= T[i].right;
        }
        root += i;
    }
    return root;
}

bool judge(int r1, int r2) {
    if (r1 == null && r2 == null) {
        return true;
    }
    if ((r1 == null && r2 != null) || (r1 != null && r2 == null)) {
        return false;
    }
    if (T1[r1].data != T2[r2].data) {
        return false;
    }
    // 分两种情况 在当前的部分已经是相等的 调用第一个if的情况 左子树相等 如果同构右子树也必须相等
    if ((T1[r1].left != null && T2[r2].left != null) && (T1[T1[r1].left].data == T2[T2[r2].left].data))  // 左儿子不为空且值相等
        return judge(T1[r1].left, T2[r2].left) && judge(T1[r1].right, T2[r2].right);
        // 如不是完全相等 则判断镜像后是否相等
    else   // 左儿子不为空且值不等  或者 某一个左儿子为空
        return judge(T1[r1].right, T2[r2].left) && judge(T1[r1].left, T2[r2].right);

}

int main() {
    int r1, r2;
    r1 = ReadData(T1);
    r2 = ReadData(T2);
    if (judge(r1, r2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}