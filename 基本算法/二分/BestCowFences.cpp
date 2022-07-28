#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5 + 10;

int n, f;
double a[MAXN], b[MAXN], sum[MAXN];

bool check(double mid) {
    // 将数列A中的值减去二分的值 + 前缀和
    for(int i = 1; i <= n; i ++ ) {
        b[i] = a[i] - mid;
        sum[i] = sum[i - 1] + b[i];
    }
    
    // 判定是否存在一个长度不小于f的子段，子段和非负
    double ans = -1e10, minn = 1e10;
    for(int i = f; i <= n; i ++ ) {
        minn = min(minn, sum[i - f]);
        ans = max(ans, sum[i] - minn);
    }
    return ans >= 0;
}

void solve() {
    double l = -1e6, r = 1e6;
    double eps = 1e-5;
    while(l + eps < r) {
        double mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else 
            r = mid;
        
    }
    cout << int(r * 1000) << "\n";
}

signed main() {
    cin >> n >> f;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    solve();
}