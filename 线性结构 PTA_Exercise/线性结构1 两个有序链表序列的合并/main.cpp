List Merge(List L1, List L2) {
    List L, p;
    PtrToNode p1 = L1 ? L1->Next : NULL;
    PtrToNode p2 = L2 ? L2->Next : NULL;
    
    L = (List)malloc(sizeof(struct Node)); // 创建新链表的头结点
    L->Next = NULL;
    p = L;

    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            p->Next = p1;
            p1 = p1->Next;
        } else {
            p->Next = p2;
            p2 = p2->Next;
        }
        p = p->Next;
    }
    
    p->Next = p1 ? p1 : p2; // 将剩余部分连接上

    if (L1) {
        L1->Next = NULL;
    }
    if (L2) {
        L2->Next = NULL;
    }

    return L;
}
