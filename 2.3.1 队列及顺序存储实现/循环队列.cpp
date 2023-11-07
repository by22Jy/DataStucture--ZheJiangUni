// 当线性顺序队列 弹出元素 数组前面会有空余的位置没有使用
// 使用循环列表减少空间浪费
// 当front == rear时，队列为空
// 当(rear+1)%Maxsize == front时，队列满 
// 队列长度为Maxsize 留出一个空位 用于判断队列满
typedef struct QNode *Queue;
struct QNode{
    ElementType Data[Maxsize];
    int rear;   // 指向队尾元素的下一个位置
    int front;  // 指向队首元素
};

// 入队
void Push(Queue *PtrQ,ElementType item)
{
    if((PtrQ->rear+1)%Maxsize == PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%Maxsize;
    PtrQ->Data[PtrQ->rear] = item;
}

// 出队
ElementType Pop(Queue *PtrQ)
{
    if(PtrQ->front == PtrQ->rear){
        printf("队列空");
        return ERROR;
    }
    else{
        PtrQ->front = (PtrQ->front+1)%Maxsize;
        return PtrQ->Data[PtrQ->front];
    }
}