#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[100010];

void solve() {
    // 差分
    for(int i = n; i > 0; i -- )
        a[i] -= a[i-1];
    int pos = 0, neg = 0;
    for(int i = 2; i <= n; i ++ )
        if(a[i] >= 0) pos += a[i];
        else neg -= a[i];
    cout << max(pos, neg) << "\n";
    cout << abs(pos - neg) + 1 << "\n"; // + 1 是采用 a[i] -= 1, a[n + 1] += 1 => a[1] 没变
    getchar();
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++ )
        cin >> a[i];
    solve();
}