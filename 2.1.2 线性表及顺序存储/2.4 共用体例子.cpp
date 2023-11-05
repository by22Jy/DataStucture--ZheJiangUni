#include<iostream>

int main()
{
    union key{
        int k;
        char c[2];
    }u;
    u.k = 258;
    std::cout<<u.c[0]<<u.c[1]<<std::endl;
    return 0;
}

//如果你的系统使用小端序（Little-Endian），那么输出可能是 u.c[0] = 2, u.c[1] = 1。
//如果你的系统使用大端序（Big-Endian），那么输出可能是 u.c[0] = 1, u.c[1] = 2。