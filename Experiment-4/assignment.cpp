//UID:24BCS10773
//Online Exam System

#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, N;
    cin >> K >> N;
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (h.size() < K) {
            h.push(x);
        } else if (x > h.top()) {
            h.pop();
            h.push(x);
        }
        if (h.size() < K)
            cout << -1 << endl;
        else
            cout << h.top() << endl;
    }
    return 0;
};
/*
Input:
2 3
5 10 1

Output:
-1
5
5
*/
