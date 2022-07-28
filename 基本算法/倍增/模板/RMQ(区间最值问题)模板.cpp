// https://www.luogu.com.cn/problem/P2880
// ST RMQ
#include <bits/stdc++.h>
using namespace std;

const int N = 5E4+10;
int h[N], n, q, a, b, minn[N][100], maxn[N][100];

void pre_max() {
    for(int i = 1; i <= n; i ++ ) maxn[i][0] = h[i];
    int t =log2(n) + 1;
    for(int j = 1; j < t; j ++ )
        for(int i = 1; i <= n - (1 << (j - 1)) + 1; i ++ )
            maxn[i][j] = max(maxn[i][j - 1], maxn[i + (1 << (j - 1))][j - 1]);
}

void pre_min() {
    for(int i = 1; i <= n; i ++ ) minn[i][0] = h[i];
    int t = log2(n) + 1;
    for(int j = 1; j < t; j ++ )
        for(int i = 1; i <= n - (1 << (j - 1)) + 1; i ++ )
            minn[i][j] = min(minn[i][j - 1], minn[i + (1 << (j - 1))][j - 1]);
}

int query_max(int l, int r) {
    int k = log2(r - l + 1);
    return max(maxn[l][k], maxn[r - (1 << k) + 1][k]);
}

int query_min(int l, int r) {
    int k = log2(r - l + 1);
    return min(minn[l][k], minn[r - (1 << k) + 1][k]);
}

signed main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ) cin >> h[i];
    pre_max();
    pre_min();
    for(int i = 1; i <= q; i ++ ) cin >> a >> b, cout << query_max(a, b) - query_min(a, b) << "\n";
}