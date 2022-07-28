#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

int p, n, m, t;

int main() {
    cin >> p;
    while(p --) {
        priority_queue<int, vector<int>, less<>> A; // 大顶
        priority_queue<int, vector<int>, greater<>> B; // 小顶
        vector<int> ans;    
        cin >> n >> m;
        for(int i = 1; i <= m; i ++ ) {
            cin >> t;
            if(B.size() == 0 || B.top() <= t) B.push(t);
            else A.push(t);
            if(B.size() - A.size() > 1)
                A.push(B.top()), B.pop();
            if(A.size() - B.size() < -1)
                B.push(A.top()), A.pop();
            if(i % 2) {
                ans.push_back(B.top());
            }
        }
        cout << n << " " << (m + 1) / 2 << "\n";
        for(int i = 0; i < (m + 1) / 2; i ++ ) {
            if(i % 10 == 0 && i != (m + 1) / 2 - 1 && i) cout << "\n";
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}