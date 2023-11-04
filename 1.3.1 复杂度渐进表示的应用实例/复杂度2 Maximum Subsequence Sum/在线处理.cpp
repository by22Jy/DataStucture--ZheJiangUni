// TODO: fix the bug
// sample换1个数字。有正负，负数开头结尾，有并列最大和	
// 全是负数的情况

#include<iostream>
using namespace std;
const int N = 10010;
int a[N];

void solve(int a[],int n){
    // 全是负数的情况
    bool isAllNegative = true;
    for(int i=0;i<n;i++) {
        if(a[i] > 0) {
            isAllNegative = false;
            break;
        }    
    }
    if(isAllNegative){
        printf("0 0 0\n");
        return;
    }
    
    int ThisSum = 0,MaxSum = 0;
    int StartNum = 0,EndNum = 0;
    for(int i=0;i<n;i++){
        ThisSum += a[i];
        if(ThisSum > MaxSum) {
            MaxSum = ThisSum;
            EndNum = i;
        }
        else if(ThisSum < 0) {
            ThisSum = 0;
            StartNum = i+1;
        }
    }
    printf("%d %d %d\n",MaxSum,a[StartNum],a[EndNum]);
}

int main()
{

    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++) scanf("%d",&a[i]);
    solve(a,k);
}