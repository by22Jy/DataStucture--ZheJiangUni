// 跟前面堆栈分析一样 链表头指向头部
typedef struct QNode *Queue;
struct Node{
    ElementType Data;
    struct Node * Next;
};

struct QNode{    // 链式队列结构
    ElementType Data;
    struct Node *rear;
    struct Node *front;
};

// 删除队列的头节点
ElementType DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    ElementType FrontElem;
    if(PtrQ->front == NULL){
        printf("队列空");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear){  // 如果队列只有一个元素
        PtrQ->front = PtrQ->rear = NULL;
    }
    else{
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

// 队尾节点增加元素
void AddQ(Queue PtrQ,ElementType item){
    struct Node *RearCell;
    RearCell = (struct Node *)malloc(sizeof(struct Node));
    RearCell->Data = item;
    RearCell->Next = NULL;
    if(PtrQ->front == NULL){    // 如果队列为空
        PtrQ->front = PtrQ->rear = RearCell;
    }
    else{
        PtrQ->rear->Next = RearCell;
        PtrQ->rear = RearCell;
    }
}