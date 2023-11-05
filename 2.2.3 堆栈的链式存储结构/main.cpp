// 在链式结构中 top该选哪个？
// 如果选择尾节点 插入可以 但是删除操作 无法指向上一个节点
// 所以堆栈中 链式结构的top节点 选在头节点
typedef struct SNode * Stack;
struct SNode{
    ElementType Data;
    struct SNode * Next;
};

// 创建堆栈
Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// 判断堆栈是否为空
int IsEmpty(Stack S){
    return (S->Next == NULL);
}

// 入栈
void Push(Stack PtrS,ElementType item){
    struct SNode * TmpCell;
    TmpCell = (struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = PtrS->Next;
    PtrS->Next = TmpCell;
}

// 出栈
ElementType Pop(Stack PtrS){
    struct SNode * FirstCell;
    ElementType TopElem;
    if(IsEmpty(PtrS)){
        printf("堆栈空");
        return ERROR;
    }
    else{
        FirstCell = PtrS->Next;
        TopElem = FirstCell->Data;
        PtrS->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}