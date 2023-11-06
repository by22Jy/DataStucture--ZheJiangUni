#include<iostream>
using namespace std;
typedef Lnode *List;
typedef struct {
    int coef;
    inr expor;
    List next;
}Lnode;

List InitList(List &L){
    L = (List)malloc(sizeof(List));
    L->next = NULL;
    return L;
}

void InsertList(List &L, int numOfCoef,int numOfExpor){
    p = (List)malloc(sizeof(List));
    // 判断只有一个空节点的情况
    if(L->next == NULL){
        p -> coef = numOfCoef;
        p -> expor = numOfExpor;
        L->next = p;
        p->next = NULL;
        return ;
    }
    // 按指数大小降序找适当位置插入
    for(auto i = L->next;i;i = i->next){
        if(numOfExpor == i->expor) i->coef += numOfCoef;
        else if(i->next != NULL && numOfExpor < i->expor && numOfExpor > i->next->expor){
            p -> coef = numOfCoef;
            p -> expor = numOfExpor;
            p->next = i->next->next;
            i->next = p;
            return ;
        }
    }
}