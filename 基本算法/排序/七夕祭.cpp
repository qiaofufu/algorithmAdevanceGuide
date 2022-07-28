#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1E5 + 10;

int n, m, t, x, y, c[N], r[N], s[N];

int func(int a[], int n, int d) {
    for(int i = 1; i <= n; i ++ )
        s[i] = s[i - 1] + a[i] - d;
    
    sort(s + 1, s + 1 + n);
    
    int mid = 0, res = 0;
    if(n % 2) mid = s[(n + 1) / 2];
    else mid = s[n / 2];
    
    for(int i = 1; i <= n; i ++ )
        res += abs(s[i] - mid);
    
    return res;
}

int col() {
    int d = t / m;
    return func(c, m, d);
}

int row() {
    int d = t / n;
    return func(r, n, d);
}

signed main() {
    cin >> n >> m >> t;
    for(int i = 1; i <= t; i ++ ) cin >> x >> y, r[x]++, c[y]++;
    if(t % n && t % m) cout << "impossible\n";
    else if(t % n) cout << "column " << col() << "\n";
    else if(t % m) cout << "row " << row() << "\n";
    else cout << "both " << col() + row() << "\n";
}