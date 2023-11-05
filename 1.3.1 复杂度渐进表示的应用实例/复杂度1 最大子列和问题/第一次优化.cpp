// 题目描述: 给定N个整数序列 求序列和的最大值
// 第一次优化 在计算i 到 j之间的子序列和时候 不需要每次都从新累加 直接利用上次计算结果
#include<iostream>

int solve(int a[],int N)
{
    int tmp_sum = 0;
    int res = 0;
    for(int i=0;i<N;i++){
        tmp_sum = 0;
        for(int j=i;j<N;j++){
            tmp_sum += a[j];
            res = std::max(res,tmp_sum);
        }
    }
    return res;
}
// 时间复杂度 o(n^2)