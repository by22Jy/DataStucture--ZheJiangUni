// TODO: fix the bug
// sample换1个数字。有正负，负数开头结尾，有并列最大和	
// 全是负数的情况

#include <iostream>
using namespace std;
const int N = 10010;
int a[N];

void solve(int a[], int n) {
    // 让MaxSum=-1 而不是0 这样可以处理所有值都是负数和都是0的情况
    // 多开一个tempstart变量 只有最大值更新时 才让start变量指向tempstart
    int ThisSum = 0, MaxSum = -1;
    int StartNum = 0, EndNum = 0;
    int tempStartNum = 0;

    for (int i = 0; i < n; i++) {
        ThisSum += a[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
            StartNum = tempStartNum;
            EndNum = i;
        }
        else if (ThisSum < 0) {
            ThisSum = 0;
            tempStartNum = i + 1;
        }
    }

    if (MaxSum < 0) {
        // 全是负数的情况
        MaxSum = 0;
        StartNum = 0;
        EndNum = n - 1;
    }

    cout << MaxSum << " " << a[StartNum] << " " << a[EndNum] << endl;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    solve(a, k);
    return 0;
}
