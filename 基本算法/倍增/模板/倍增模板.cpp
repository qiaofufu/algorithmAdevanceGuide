#include <bits/stdc++.h>

using namespace std;

const int N = 1E5+10;

int n, s[N], t;

void solve() {
    int k = 0, p = 1;
    while(p) {
        if(s[k + p] <= t) {
            k += p; // s[k + p] 满足条件， 更新初始点
            p *= 2; // 倍增偏移值
        } else p /=2; // s[k + p] 不满足条件， 倍减偏移值，直至偏移值为0
    }
    cout << k << "\n";
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> s[i], s[i] += s[i - 1]; // 读入的同时进行前缀和
    while(cin >> t && t) {
        solve();
    }
}