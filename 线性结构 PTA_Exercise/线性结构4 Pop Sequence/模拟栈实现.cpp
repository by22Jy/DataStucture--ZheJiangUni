#include<iostream>
#include<vector>
using namespace std;
const int N = 1010;
class Stack{
    public:
    Stack() : top(-1) {}
    void Push(int e);
    void Pop();
    bool Empty();
    int Top();
    int Size();
    int num[N];
    int top;
};

void Stack::Push(int e){
    this->num[++top] = e;
}

void Stack::Pop(){
    this->top --;
}

bool Stack::Empty(){
    return top == -1;
}

int Stack::Top() {
    return num[top];
}

int Stack::Size(){
    return top+1;
}

bool isPossiblePopSequence(int M,int N,vector<int> pop_sequence){
    Stack s = Stack();
    int num = 1;
    for(auto i:pop_sequence){
        while(s.Empty() || s.Top()!=i) {
            s.Push(num++);
            if(s.Size()>M)
                return false;
        }
        if(s.Top() == i){
            s.Pop();
        }
    }
    return s.Empty();
}

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    
    for (int i = 0; i < K; i++) {
        vector<int> pop_sequence(N);
        for (int j = 0; j < N; j++) {
            cin >> pop_sequence[j];
        }
        
        if (isPossiblePopSequence(M, N, pop_sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}