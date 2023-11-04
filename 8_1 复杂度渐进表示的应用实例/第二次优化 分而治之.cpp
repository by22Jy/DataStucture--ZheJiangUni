    // 题目描述: 给定N个整数序列 求序列和的最大值
    // 通过分而治之的思想 可以划分为每小块去处理

    #include<iostream>
    using namespace std;
    const int N = 100010;
    int a[N];

    int MaxOfThreeNum(int a,int b,int c){
        return max(max(a,b),c);
    }

    int DivideAndSolve(int List[],int l,int r)
    {
        // 分为左右两边 分别选出 左边最大值 右边最大值 和跨过中间的最大值 共同选出最大值
        
        // 递归处理的返回条件
        if(l == r){
            if (List[l]>0) return List[l];
            return 0;   // 根据题目要求 如果最大子列和为负 则返回0 
        }
        // 存放左右两个区间各自的最大值
        int MaxLeftNum = 0,MaxRightNum = 0;
        // 存放左边跨越中线的最大值   存放右边跨越中线的最大值
        int MaxLeftBorderNum = 0, MaxRightBorderNum = 0;
        // 分开处理
        int center = l+r>>1;
        MaxLeftNum = DivideAndSolve(List,l,center);
        MaxRightNum = DivideAndSolve(List,center+1,r);
        // 求跨分界线的子列和
        int LeftBorderSum=0,RightBorderSum=0;
        for(int i=center;i>=l;i--){
            LeftBorderSum += List[i];
            if(LeftBorderSum > MaxLeftBorderNum)
                MaxLeftBorderNum = LeftBorderSum;
        }
        for(int j = center+1;j<=r;j++)
        {
            RightBorderSum += List[j];
            if(RightBorderSum > MaxRightBorderNum)
                MaxRightBorderNum = RightBorderSum;
        }

        // 治关键 求出每一小部分的最大值 进行返回 来计算
        return MaxOfThreeNum(MaxLeftNum,MaxRightNum,MaxLeftBorderNum+MaxRightBorderNum);
    }

    int solve(int a[],int N)
    {    
        return DivideAndSolve(a,0,N-1);   
    }

    int main()
    {
        int K;
        scanf("%d",&K);
        for(int i=0;i<K;i++) scanf("%d",&a[i]);
        printf("%d\n",solve(a,K));
    }