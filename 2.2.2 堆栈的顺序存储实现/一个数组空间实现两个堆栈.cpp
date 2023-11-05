// 两个指针指向头尾 都往中间移动 最大限度利用空间
#define Maxsize 100
struck DStack{
    ElementType Data[Maxsize];
    int Top1;   // 堆栈1的指针
    int Top2;   // 堆栈2的指针
}S;

// 当两个指针相遇时 堆栈满
// 入栈操作
void Push(DStack *PtrS,ElementType item,int Tag)
{
    // Tag 标签位 指明对哪个堆栈进行操作 1为堆栈1 2为堆栈2
    if(PtrS->Top2 - PtrS->Top1 == 1){
        printf("堆栈满");
        return;
    }
    if(Tag == 1) PtrS->Data[++(PtrS->Top1)] = item;
    else PtrS->Data[--(PtrS->Top2)] = item;
}

// 出栈操作
ElementType Pop(DStack *PtrS,int Tag)
{
    if(Tag == 1){
        if(PtrS->Top1 == -1){
            printf("堆栈1空");
            return ERROR;
        }
        else return PtrS->Data[(PtrS->Top1)--];
    }
    else{
        if(PtrS->Top2 == Maxsize){
            printf("堆栈2空");
            return ERROR;
        }
        else return PtrS->Data[(PtrS->Top2)++];
    }
}