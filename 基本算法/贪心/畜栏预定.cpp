#include <bits/stdc++.h>

using namespace std;

const int N = 5E4+10;
pair<int, pair<int, int>> cattle[N];
int n, c[N];

void solve() {
    sort(cattle + 1, cattle + 1 + n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prq;
    prq.push({cattle[1].second.first, 1});
    c[cattle[1].second.second] = 1;
    for(int i = 2; i <= n; i ++ ) {
        int l = cattle[i].first, r = cattle[i].second.first, idx = cattle[i].second.second;
        auto f = prq.top(); 
        if(f.first < l) {
            prq.pop();
            c[idx] = f.second;
            prq.push({r, f.second});
        } else {
            c[idx] = prq.size() + 1;
            prq.push({r, prq.size() + 1});
        }
    }
    cout << prq.size() << "\n";
    for(int i = 1; i <= n; i ++ )
        cout << c[i] << "\n";
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> cattle[i].first >> cattle[i].second.first, cattle[i].second.second = i;
    solve();
}