// Title: 在线处理
// 时间复杂度O(N)   

int MaxSubseqSum4(int a[], int N) {
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    for(int i = 0; i < N; i++) {
        ThisSum += a[i];
        if(ThisSum > MaxSum) {  // 更大的总和 更新
            MaxSum = ThisSum;
        } else if(ThisSum < 0) { // 如果小于0 证明前面的子序列已经对于最大值不起效果 重制
            ThisSum = 0;
        }
    }
    return MaxSum;
}