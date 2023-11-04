#include<iostream>
#include<time.h>
#include <cmath>

// 最大项系数
clock_t start, stop; 
// clock_t is the return type of clock() function, and its unit is clock tick
double duration;
// record time
// const unsigned long MANX = static_cast<unsigned long>(10000010);
#define MANX 1000010
double a[MANX];

void init() {
    for(int i = 0; i < MANX; i++) {
        a[i] = (double)i;
    }
}

double f1(int n, double a[], double x) {
    double p = a[0];
    for(int i = 1; i <= n; i++) {
        p += (a[i] * pow(x, i));
    }
    return p;
}

double f2(int n,double a[],double x)
{
    int i;
    double p = a[n];
    for(i = n;i > 0;i--)
    {
        p = a[i-1] + x * p;
    }
    return p;

}

double RecordTime(int n,double a[],double x,double (*f)(int,double[],double))
{
    start = clock();
    (*f)(n,a,x);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;  // 得到以秒为单位的时间
    return duration;
}


int main()
{
    init();
    double x = 1.1;
    double t1 = RecordTime(MANX,a,x,f1);
    double t2 = RecordTime(MANX,a,x,f2);
    printf("t1 = %f\n",t1);
    printf("t2 = %f\n",t2);
    return 0;
}

//t1 = 176.710000
//t2 = 56.290000
// 在大数据量的情况下 第二种算法会快很多