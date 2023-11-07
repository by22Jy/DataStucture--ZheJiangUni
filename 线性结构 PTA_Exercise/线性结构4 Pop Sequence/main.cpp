// 模拟遍历他给的每种情况的每个数 通过栈来模拟可能的出栈序列

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPossiblePopSequence(int M, int N, vector<int>& sequence) {
    stack<int> st;
    int num = 1;

    for (int i = 0; i < N; i++) {
        while (st.empty() || st.top() != sequence[i]) {
            st.push(num++);
            if (st.size() > M) {
                return false;
            }
        }

        if (st.top() == sequence[i]) {
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        vector<int> sequence(N);
        for (int j = 0; j < N; j++) {
            cin >> sequence[j];
        }

        if (isPossiblePopSequence(M, N, sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
