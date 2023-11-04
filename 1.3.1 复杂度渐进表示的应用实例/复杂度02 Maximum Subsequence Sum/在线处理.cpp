#include<iostream>
using namespace std;
const int N = 10010;
int a[N];

void solve(int a[],int N){
    int ThisSum = 0,MaxSum = 0;
    int StartNum = 0,EndNum = 0;
    for(int i=0;i<N;i++){
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
    for(int i=0;i<k;i++) scanf("%d",&a[i]);
    solve(a,k);
}