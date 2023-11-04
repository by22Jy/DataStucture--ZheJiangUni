// 题目描述: 给定N个整数序列 求序列和的最大值
// 解法描述: 暴力枚举
#include<iostream>

int solve(int a[],int N)
{
    int tmp_sum = 0;
    int res = 0;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            tmp_sum = 0;
            for(int k=i;k<=j;k++){
                tmp_sum += a[k];
            }
            res = std::max(res,tmp_sum);
        }
    }
    return res;
}
// 时间复杂度 o(n^3)