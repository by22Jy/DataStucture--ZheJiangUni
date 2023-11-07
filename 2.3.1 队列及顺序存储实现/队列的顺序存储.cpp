// 队列是先进先出
#define Maxsize 100
typedef struct QNode *Queue;
struct QNode{
    ElementType Data[Maxsize];
    int rear;   // 指向队尾元素的下一个位置
    int front;  // 指向队首元素
};


