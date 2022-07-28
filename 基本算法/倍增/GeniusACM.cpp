#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5E5+100;
int k, n, m, t, a[N], b[N];

int calc(int x, int y) {
    // cout << x << " " << y << " = " << pow(y - x, 2) << "\n";
    return pow(y - x, 2);
}

bool check(int l, int r) {
    if(r > n) return false;
    // cout << "check(" << l << "," << r <<") ";
    int kk = 1, sum = 0;
    for(int i = l; i <= r; i ++ ) b[kk++] = a[i];
    sort(b + 1, b + kk);
    for(int i = 1, j = kk - 1; i < j && i <= m; i++, j --) {
        sum += calc(b[i], b[j]);
    }
    // cout << "sum = " << sum << "\n";
    return sum <= t;
}

void solve() {
    int cnt = 0;
    int l = 1, r = 1;
    while(l <= n) {
        int p = 1;
        r = l;
        while(p) {
            if(check(l, r + p)) {
                r += p;
                p *= 2;
            } else {
                p /= 2;
            }
        }
        cnt ++;
        // cout << l << " " << r << "\n";
        l = r + 1;   
    }
    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);   
    cin >> k;
    while(k --) {
        cin >> n >> m >> t;
        for(int i = 1; i <= n; i ++ ) cin >> a[i];
        solve();
    }
}